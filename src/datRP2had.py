#!/usr/bin/env python

import sys
from xml.dom.minidom import Document

""" Converts an old style dat design file to XML based format

    Error checks are kept to a minium
    TODO: add error checks later

    Prints XML to stdout
"""
#a colormap that is hardcoded in the old code (declare.h)
#while converting dat files these values should be used
datColorMap = [
    '808080',   #GREY       0
    '000000',   #BLACK      1
    'ffffff',   #WHITE      2
    'ff0000',   #RED        3
    '008000',   #GREEN      4
    '0000ff',   #BLUE       5
    '00ffff',   #CYAN       6
    'ff00ff',   #MAGENTA    7
    'ffff00',   #YELLOW     8
    'fa8072',   #SALMON     9
    'a52a2a'    #BROWN     10
]

reflSymTypeMap = ['REFL_NONE', 'REFL_EDGE_BISECTOR', 'REFL_PGON_RADIUS' ]


def addElem(parent, typeVal, fillVal, cidVal):
    elem = doc.createElement('elem')
    elem.setAttribute('type', typeVal)
    parent.appendChild(elem)
    fill = doc.createElement('fill')
    elem.appendChild(fill)
    text = doc.createTextNode(fillVal)
    fill.appendChild(text)
    cid = doc.createElement('cid')
    elem.appendChild(cid)
    text = doc.createTextNode(str(cidVal))
    cid.appendChild(text)
    return elem

def addPt(parent, xVal, yVal):
    pt = doc.createElement('pt')
    parent.appendChild(pt)
    x = doc.createElement('x')
    pt.appendChild(x)
    text = doc.createTextNode(tokens[0])
    x.appendChild(text)
    y = doc.createElement('y')
    pt.appendChild(y)
    text = doc.createTextNode(tokens[1])
    y.appendChild(text)


try:
    dat = open(sys.argv[1], 'r')
except IndexError:
    print 'usage: ' + sys.argv[0] + ' <datfile>'
    sys.exit(-1)
except IOError:
    print "Failed to open '" + sys.argv[1] + "'"
    sys.exit(-2)

#process first line
line = dat.readline()
tokens = line.split()

pVal = int(tokens[0])
numColors = int(tokens[4])


doc = Document()
design = doc.createElement('design')
design.setAttribute('type', "REGULAR_PGON")
doc.appendChild(design) #root element added to dom tree
metadata = doc.createElement('metadata')
design.appendChild(metadata)
colors = doc.createElement('colors')
colors.setAttribute('count', tokens[4])
metadata.appendChild(colors)

for i in range(int(tokens[4])):
    color = doc.createElement('color')
    colors.appendChild(color)
    cid = doc.createElement('cid')
    color.appendChild(cid)
    cidText = doc.createTextNode(str(i))
    cid.appendChild(cidText)
    hex = doc.createElement('hex')
    color.appendChild(hex)
    hexText = doc.createTextNode(datColorMap[i+1])
    hex.appendChild(hexText)

p = doc.createElement('p')
design.appendChild(p)
text = doc.createTextNode(str(tokens[0]))
p.appendChild(text)

q = doc.createElement('q')
design.appendChild(q)
text = doc.createTextNode(str(tokens[1]))
q.appendChild(text)

fund_reg_edges = doc.createElement('fund_reg_edges')
design.appendChild(fund_reg_edges)
text = doc.createTextNode(str(tokens[2]))
fund_reg_edges.appendChild(text)

refl_sym_type = doc.createElement('refl_sym_type')
design.appendChild(refl_sym_type)
text = doc.createTextNode(reflSymTypeMap[int(tokens[5])])
refl_sym_type.appendChild(text)

#process second line
line = dat.readline()
tokens = line.split()

color_perm_rotn = doc.createElement('color_perm_rotn')
design.appendChild(color_perm_rotn)
for i in tokens:
    perm = doc.createElement('perm')
    color_perm_rotn.appendChild(perm)
    text = doc.createTextNode(str(int(i)-1))
    perm.appendChild(text)

#process third line
line = dat.readline()
tokens = line.split()

color_perm_refl = doc.createElement('color_perm_refl')
design.appendChild(color_perm_refl)
for i in tokens:
    perm = doc.createElement('perm')
    color_perm_refl.appendChild(perm)
    text = doc.createTextNode(str(int(i)-1))
    perm.appendChild(text)

#next pVal lines will have adjacency information
adjacency = doc.createElement('adjacency')
design.appendChild(adjacency)
for i in range(pVal):
    line = dat.readline()
    tokens = line.split()
    entry = doc.createElement('entry')
    entry.setAttribute('e', str(i))
    adjacency.appendChild(entry)
    orientation = doc.createElement('orientation')
    entry.appendChild(orientation)
    if(int(tokens[0]) > 0):
        text = doc.createTextNode('ROTATION')
        orientation.appendChild(text)
    else:
        text = doc.createTextNode('REFLECTION')
        orientation.appendChild(text)
    edge = doc.createElement('edge')
    entry.appendChild(edge)
    text = doc.createTextNode(str(abs(int(tokens[0])-1)))
    edge.appendChild(text)
    color_perm = doc.createElement('color_perm')
    entry.appendChild(color_perm)
    for j in range(1,numColors+1):
        perm = doc.createElement('perm')
        color_perm.appendChild(perm)
        text = doc.createTextNode( str(int(tokens[j])-1) )
        perm.appendChild(text)

#Now we begin vertex processing
#we build elements list according to the vertex list in the dat file
line = dat.readline()
tokens = line.split()
numPoints = int(tokens[0]) #the only entry on this line is num of points

elements = doc.createElement('elements')
design.appendChild(elements)

#next numPoints lines will have vertex info
#we group vertexex into element groups using their type-of-point field
lines = []
for line in dat.readlines():
    if(line != '\n'): lines.append(line)
lines = lines[0:numPoints]

i = 0
prevTypeOfPoint = 0
for line in lines:
    tokens = line.split()
    #we don't begin a new <elem> node for every vertex
    #so check the type-of-point field
    #type-of-point = 1 (moveto) is treated as 2

    typeOfPoint = int(tokens[3])
    if(typeOfPoint == 1):
        elem = addElem(elements, 'EUCLID_POLYLINE', 'false', int(tokens[2])-1)
        points = doc.createElement('points')
        elem.appendChild(points)
        addPt(points, tokens[0], tokens[1])
    elif(typeOfPoint == 2):
        addPt(points, tokens[0], tokens[1])
    elif(typeOfPoint == 3):
        if(prevTypeOfPoint != 3):
            elem = addElem(elements, 'CIRCLE', 'false', int(tokens[2])-1)
            points = doc.createElement('points')
            elem.appendChild(points)
            addPt(points, tokens[0], tokens[1])
        else:
            addPt(points, tokens[0], tokens[1])
            
    elif(typeOfPoint == 4):
        elem = addElem(elements, 'EUCLID_POLY', 'true', int(tokens[2])-1)
        points = doc.createElement('points')
        elem.appendChild(points)
        addPt(points, tokens[0], tokens[1])
        
    elif(typeOfPoint == 5):
        addPt(points, tokens[0], tokens[1])
        
    elif(typeOfPoint == 7):
        if(prevTypeOfPoint != 7):
            elem = addElem(elements, 'HYPER_POLYLINE', 'false', int(tokens[2])-1)
            points = doc.createElement('points')
            elem.appendChild(points)
            addPt(points, tokens[0], tokens[1])
        else:
            addPt(points, tokens[0], tokens[1])
            
    elif(typeOfPoint == 8): #filled circle
        if(prevTypeOfPoint != 8):
            elem = addElem(elements, 'CIRCLE', 'true', int(tokens[2])-1)
            points = doc.createElement('points')
            elem.appendChild(points)
            addPt(points, tokens[0], tokens[1])
        else:
            addPt(points, tokens[0], tokens[1])
            
    elif(typeOfPoint == 9):
        elem = addElem(elements, 'EUCLID_POLYLINE', 'false', int(tokens[2])-1)
        points = doc.createElement('points')
        elem.appendChild(points)
        addPt(points, tokens[0], tokens[1])
        
    elif(typeOfPoint == 10):
        addPt(points, tokens[0], tokens[1])

    elif(typeOfPoint == 12):
        elem = addElem(elements, 'HYPER_POLY', 'true', int(tokens[2])-1)
        points = doc.createElement('points')
        elem.appendChild(points)
        addPt(points, tokens[0], tokens[1])

    elif(typeOfPoint == 13):
        addPt(points, tokens[0], tokens[1])
        
    prevTypeOfPoint = typeOfPoint

    
#print the dom tree to stdout as an xml document
print doc.toprettyxml()


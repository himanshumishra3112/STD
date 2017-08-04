from xml.dom import minidom

doc=minidom.parse("test.xml")

name=doc.getElementsByTagName("country")
rank=doc.getElementsByTagName("rank")

print name
print rank

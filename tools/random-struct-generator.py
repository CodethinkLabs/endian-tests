import random

structSize = {}

def makeStructure(structno):
    print "typedef struct _teststruct%d_t {"%structno
    for i in range(0,4):
        print "    int field%d:%d;"%(i,random.randint(1,32))
    print "} teststruct%d_t;"%structno

def makeAccess(structno):
    print "    teststruct%d_t teststruct%d;"%(structno,structno)

    print "    bzero(&teststruct%d, sizeof(teststruct%d_t));"%(structno, structno);
    for i in range(0,4):
        print "    teststruct%d.field%d = 0x%8.8X;"%(structno, i, random.randint(0,2**32))
    print "    printf(\"size of structure %%d == %%d\\n\",%d,sizeof(teststruct%d_t));"%(structno,structno)

    samples = []
    print "    unsigned char* byteaccess%d = (unsigned char*) &teststruct%d;"%(structno, structno)
    for i in range(0,10):
        samples.append("byteaccess%d[%d %% sizeof(teststruct%d_t)]"%(structno, random.randint(0,1023), structno)) # I know that isn't truly random
    print "    printf(\"byte samples: %s\\n\",%s);"%("%2.2X "*10, ",".join(samples))

def makeMain():
    print "int main()"
    print "{"
    for i in range(0,10): makeAccess(i)
    print "}"

if __name__=="__main__":
    for i in range(0,10): makeStructure(i)
    makeMain()

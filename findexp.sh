#########################################################################
# File Name: findexp.sh
# Author: ma6174
# mail: ma6174@163.com
# Created Time: 2015年10月29日 星期四 11时06分31秒
#########################################################################
#!/bin/bash


find . -iname \*.[ch] -exec grep --color -wn -H $1 \{\} \;
find . -iname \*.cpp -exec grep --color -wn -H $1 \{\} \;

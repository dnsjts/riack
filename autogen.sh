git submodule update --recursive 

libtoolize --force --copy
aclocal -I m4 --install
autoheader
automake --foreign --add-missing --copy
autoconf


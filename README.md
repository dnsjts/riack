Riak C client library
=====================

[![Build Status](https://img.shields.io/travis/dnsjts/riack/master.svg?style=flat-square)](https://travis-ci.org/algernon/riack)
[![Coverage Status](https://coveralls.io/repos/dnsjts/riack/badge.svg?style=flat-square)](https://coveralls.io/r/algernon/riack)

This is a C client library for the [Riak][riak] distributed NoSQL
database.

 [riak]: http://basho.com/products/riak-kv/

The library uses [semantic versioning][semver].

 [semver]: http://semver.org/

Features
--------

... todo ...

Demo
----

... todo ...

Installation
------------

The library follows the usual autotools way of installation:

    $ git clone git://github.com/algernon/riack.git
    $ cd riack
    $ git submodule update --init
    $ autoreconf -i
    $ ./configure && make && make check && make install

For the build to succeed, one will need libtool 2.2+ (only if building
from a git checkout), the [protobuf-c compiler][protoc].

 [protoc]: http://protobuf-c.googlecode.com

From this point onward, the library is installed and fully functional,
and one can use `pkg-config` to compile programs against it:

    ${CC} $(pkg-config --cflags --libs riack) demo.c -o demo -Wall

If, for some reason the build fails, one may need to regenerate the
`protobuf-c-compiler` generated headers (changes in the compiler are
known to cause issues). To do this, do a `make distclean` first, and
then start over from `configure`.

To build the API documentation, one will have to have
[Doxygen](http://www.doxygen.org/) installed.

License
-------

Copyright (C) 2015 Gergely Nagy <algernon@madhouse-project.org> and
Parth Oberoi <htrapdev@gmail.com>, released under the terms of the
[GNU Lesser General Public License][lgpl], version 3+.

 [lgpl]: http://www.gnu.org/licenses/lgpl.html

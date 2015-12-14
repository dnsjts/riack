# -- Global settings --

noinst_LTLIBRARIES				= \
	lib/libriack.la

riak_proto_files		= \
	lib/riack/proto/riak.pb-c.c  \
	lib/riack/proto/riak.pb-c.h
riak_kv_proto_files		= \
	lib/riack/proto/riak_kv.pb-c.c  \
	lib/riack/proto/riak_kv.pb-c.h
riak_dt_proto_files		= \
	lib/riack/proto/riak_dt.pb-c.c  \
	lib/riack/proto/riak_dt.pb-c.h
noinst_HEADERS		= \
	lib/riack/proto/riak.pb-c.h \
	lib/riack/proto/riak_kv.pb-c.h  \
	lib/riack/proto/riak_dt.pb-c.h \
	lib/riack/_private.h

dist_lib_libriack_la_SOURCES	= \
	lib/riack/client.h	  \
	lib/riack/content.h	  \
	lib/riack/riack.h   \
	lib/riack/putreq.h  \
	lib/riack/message.h \
	lib/riack/dtupdatereq.h \
	lib/riack/dtop.h \
	lib/riack/setop.h \
	lib/riack/client.c	  \
	lib/riack/content.c    \
	lib/riack/putreq.c  \
	lib/riack/dtupdatereq.c  \
	lib/riack/dtop.c  \
	lib/riack/setop.c
nodist_lib_libriack_la_SOURCES =  \
     ${riak_proto_files}    \
     ${riak_kv_proto_files} \
     ${riak_dt_proto_files}

lib_libriack_la_CFLAGS	 =  \
	-I$(top_srcdir)/lib   \
	-I$(top_builddir)/lib \
	${PROTOBUF_C_CFLAGS}
lib_libriack_la_LDFLAGS    = \
	${PROTOBUF_C_LIBS}

${riak_proto_files}: ${top_srcdir}/${proto_dir}/riak.proto
	${AM_V_at} ${mkinstalldirs} ${top_builddir}/${proto_dest_dir}
	${AM_V_GEN} protoc-c $^ -I${top_srcdir}/${proto_dir} --c_out=${top_builddir}/${proto_dest_dir}

${riak_kv_proto_files}: ${top_srcdir}/${proto_dir}/riak_kv.proto
	${AM_V_at} ${mkinstalldirs} ${top_builddir}/${proto_dest_dir}
	${AM_V_GEN} protoc-c $^ -I${top_srcdir}/${proto_dir} --c_out=${top_builddir}/${proto_dest_dir}

${riak_dt_proto_files}: ${top_srcdir}/${proto_dir}/riak_dt.proto
	${AM_V_at} ${mkinstalldirs} ${top_builddir}/${proto_dest_dir}
	${AM_V_GEN} protoc-c $^ -I${top_srcdir}/${proto_dir} --c_out=${top_builddir}/${proto_dest_dir}

$(lib_libriack_la_OBJECTS): ${riak_proto_files} ${riak_kv_proto_files} ${riak_dt_proto_files}

CLEANFILES			= ${riak_proto_files} ${riak_kv_proto_files} ${riak_dt_proto_files}

proto_dir = ext/riak_pb/src
proto_dest_dir = lib/riack/proto

# -- Testcases --
if HAVE_CHECK
tests_TESTS = tests/check_libriack

tests/check_%: CFLAGS += ${CHECK_CFLAGS} \
	${lib_libriack_la_CFLAGS}
tests/check_%: LDADD += ${CHECK_LIBS} -ldl \
	lib/libriack.la ${PROTOBUF_C_LIBS}
tests/check_%: LDFLAGS += -no-install

check_PROGRAMS = ${tests_TESTS}
endif

check_libriack_srcs = tests/tests.h             \
					  tests/check_client.c      \
					  tests/check_content.c     \
					  tests/check_libriack.c    \
					  tests/check_putreq.c      \
					  tests/check_dtupdatereq.c \
					  tests/check_setop.c       \
					  tests/check_dtop.c

# -- Extra files to distribute --
EXTRA_DIST = ext \
			 ${check_libriack_srcs}

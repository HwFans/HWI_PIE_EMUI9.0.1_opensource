/*
 * The most of error symbles shall have unique value
 * I try to test every symble in a loop. There
 * are two kind symbles, one have unique value, the others
 * can have same value with certain other symbles
 * Author:ysun@lnxw.com
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define PTP_PASS        0
#define PTP_FAIL        1
#define PTP_UNRESOLVED  2
#define PTP_NOTINUSE    3
#define PTP_UNSUPPORTED 4
#define PTP_UNTESTED    5
#define PTP_UNINITIATED 6
#define PTP_NORESULT    7

struct unique {
	int value;
	char *name;
	int duplicate;
} sym[] = { {
E2BIG, "E2BIG", E2BIG}, {
EACCES, "EACCES", EACCES}, {
EADDRINUSE, "EADDRINUSE", EADDRINUSE}, {
EADDRNOTAVAIL, "EADDRNOTAVAIL", EADDRNOTAVAIL}, {
EAFNOSUPPORT, "EAFNOSUPPORT", EAFNOSUPPORT}, {
EAGAIN, "EAGAIN", EWOULDBLOCK}, {
EALREADY, "EALREADY", EALREADY}, {
EBADF, "EBADF", EBADF}, {
EBADMSG, "EBADMSG", EBADMSG}, {
EBUSY, "EBUSY", EBUSY}, {
ECANCELED, "ECANCELED", ECANCELED}, {
ECHILD, "ECHILD", ECHILD}, {
ECONNABORTED, "ECONNABORTED", ECONNABORTED}, {
ECONNREFUSED, "ECONNREFUSED", ECONNREFUSED}, {
ECONNRESET, "ECONNRESET", ECONNRESET}, {
EDEADLK, "EDEADLK", EDEADLK,}, {
EDESTADDRREQ, "EDESTADDRREQ", EDESTADDRREQ}, {
EDOM, "EDOM", EDOM}, {
EDQUOT, "EDQUOT", EDQUOT}, {
EEXIST, "EEXIST", EEXIST}, {
EFAULT, "EFAULT", EFAULT}, {
EFBIG, "EFBIG", EFBIG}, {
EHOSTUNREACH, "EHOSTUNREACH", EHOSTUNREACH}, {
EIDRM, "EIDRM", EIDRM}, {
EILSEQ, "EILSEQ", EILSEQ}, {
EINPROGRESS, "EINPROGRESS", EINPROGRESS}, {
EINTR, "EINTR", EINTR}, {
EINVAL, "EINVAL", EINVAL}, {
EIO, "EIO", EIO}, {
EISCONN, "EISCONN", EISCONN}, {
EISDIR, "EISDIR", EISDIR}, {
ELOOP, "ELOOP", ELOOP}, {
EMFILE, "EMFILE", EMFILE}, {
EMLINK, "EMLINK", EMLINK}, {
EMSGSIZE, "EMSGSIZE", EMSGSIZE}, {
EMULTIHOP, "EMULTIHOP", EMULTIHOP}, {
ENAMETOOLONG, "ENAMETOOLONG", ENAMETOOLONG}, {
ENETDOWN, "ENETDOWN", ENETDOWN}, {
ENETRESET, "ENETRESET", ENETRESET}, {
ENETUNREACH, "ENETUNREACH", ENETUNREACH}, {
ENFILE, "ENFILE", ENFILE}, {
ENOBUFS, "ENOBUFS", ENOBUFS},
#ifdef ENODATA
{
ENODATA, "ENODATA", ENODATA},
#endif
{
ENODEV, "ENODEV", ENODEV}, {
ENOENT, "ENOENT", ENOENT}, {
ENOEXEC, "ENOEXEC", ENOEXEC}, {
ENOLCK, "ENOLCK", ENOLCK}, {
ENOLINK, "ENOLINK", ENOLINK}, {
ENOMEM, "ENOMEM", ENOMEM}, {
ENOMSG, "ENOMSG", ENOMSG}, {
ENOPROTOOPT, "ENOPROTOOPT", ENOPROTOOPT}, {
ENOSPC, "ENOSPC", ENOSPC},
#ifdef ENOSR
{
ENOSR, "ENOSR", ENOSR},
#endif
#ifdef ENOSTR
{
ENOSTR, "ENOSTR", ENOSTR},
#endif
{
ENOSYS, "ENOSYS", ENOSYS}, {
ENOTCONN, "ENOTCONN", ENOTCONN}, {
ENOTDIR, "ENOTDIR", ENOTDIR}, {
ENOTEMPTY, "ENOTEMPTY", ENOTEMPTY}, {
ENOTSOCK, "ENOTSOCK", ENOTSOCK}, {
ENOTSUP, "ENOTSUP", ENOTSUP}, {
ENOTTY, "ENOTTY", ENOTTY}, {
ENXIO, "ENXIO", ENXIO}, {
EOPNOTSUPP, "EOPNOTSUPP", EOPNOTSUPP}, {
EOVERFLOW, "EOVERFLOW", EOVERFLOW}, {
EPERM, "EPERM", EPERM}, {
EPIPE, "EPIPE", EPIPE}, {
EPROTO, "EPROTO", EPROTO}, {
EPROTONOSUPPORT, "EPROTONOSUPPORT", EPROTONOSUPPORT}, {
EPROTOTYPE, "EPROTOTYPE", EPROTOTYPE}, {
ERANGE, "ERANGE", ERANGE}, {
EROFS, "EROFS", EROFS}, {
EWOULDBLOCK, "EWOULDBLOCK", EAGAIN}, {
EXDEV, "EXDEV", EXDEV}, {
0, 0, 0}
};

int main()
{
	struct unique *tst;
	int i, ret = PTP_PASS;
	tst = sym;

	while (tst->name) {
		for (i = 0; sym[i].name; i++) {
			if (tst->value == sym[i].value && tst->duplicate != sym[i].value && strcmp(tst->name, sym[i].name)) {	//In case EAGAIN is not equal to EWOULDBLOCK,compare the name
				printf("%s has a duplicate value with %s\n",
				       tst->name, sym[i].name);
				ret = PTP_FAIL;
			}
		}
		tst++;
	}
	return ret;
}
#include "addon.h"
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <strings.h>

const char* errno_string(int errorno);

bool find_string(const char* string, const char* array[], size_t s) {
  for (size_t i = 0; i < s; i++) {
    if (!strcasecmp(string, array[i])) {
      return true;
    }
  }
  return false;
}

bool find_int(const int value, const int array[], size_t s) {
  for (size_t i = 0; i < s; i++) {
    if (value == array[i]) {
      return true;
    }
  }
  return false;
}

#if NODE_VERSION_AT_LEAST(0, 11, 0)
void throw_error(v8::Isolate* isolate, const char* format, ...) {
#else
void throw_error(const char* format, ...) {
#endif
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer, 156, format, args);
  va_end(args);

  THROW_EXCEPTION(v8::Exception::Error(STRING(buffer)));
}

v8::Local<v8::Value> ErrnoException(v8::Isolate* isolate, int errorno, const char* syscall) {
    v8::Local<v8::String> errno_string = STRING(::errno_string(errorno));
    v8::Local<v8::Value> exception_error = v8::Exception::Error(STRING(strerror(errorno)));
    v8::Local<v8::Object> error_object = exception_error->ToObject(isolate);
    error_object->Set(STRING("errno"), errno_string);
    error_object->Set(STRING("code"), errno_string);
    error_object->Set(STRING("syscall"), STRING(syscall));
    error_object->Set(STRING("path"), STRING(""));

    return exception_error;
}

const char* errno_string(int errorno) {
  switch(errorno) {
    ERRNO_CASE(EACCES);
    ERRNO_CASE(EDQUOT);
    ERRNO_CASE(EEXIST);
    ERRNO_CASE(EFAULT);
    ERRNO_CASE(EFBIG);
    ERRNO_CASE(EINTR);
    ERRNO_CASE(EINVAL);
    ERRNO_CASE(EISDIR);
    ERRNO_CASE(ELOOP);
    ERRNO_CASE(EMFILE);
    ERRNO_CASE(ENAMETOOLONG);
    ERRNO_CASE(ENFILE);
    ERRNO_CASE(ENODEV);
    ERRNO_CASE(ENOENT);
    ERRNO_CASE(ENOMEM);
    ERRNO_CASE(ENOSPC);
    ERRNO_CASE(ENOTDIR);
    ERRNO_CASE(ENXIO);
    ERRNO_CASE(EOPNOTSUPP);
    ERRNO_CASE(EOVERFLOW);
    ERRNO_CASE(EPERM);
    ERRNO_CASE(EROFS);
    ERRNO_CASE(ETXTBSY);
    ERRNO_CASE(ENOTTY);
    ERRNO_CASE(EBADF);
    ERRNO_CASE(EAGAIN);
    ERRNO_CASE(ENOSYS);
    ERRNO_CASE(EIO);
    ERRNO_CASE(ELIBBAD);
    ERRNO_CASE(ENOEXEC);
    ERRNO_CASE(E2BIG);
    default: return "";
  }
}
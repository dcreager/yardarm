# Yardarm

The Yardarm is a type introspection library for C.  It gives you enough rope to
provide descriptions of the C types used in your program, which you can access
during compilation or at runtime.  Think of it as a C version of C++'s
[RTTI](http://en.wikipedia.org/wiki/Run-time_type_information) or Java's
reflection API.


## Why?

A common complaint about C is the amount of boilerplate code that you have to
write.  Often, this boilerplate is completely uninteresting "turn the crank"
code that only depends on the stucture of one of your C types.  One way around
this problem is to use code generation to automatically produce all of the
annoying boilerplate from a nicer, more conside description of the type.

Another option is to provide a single, generic implementation of the boilerplate
code, that would work with *any* type.  To do this, the generic implementation
would need information, at runtime, about the types involved.  All the usual
benefits of type introspection, but for C.


## Isn't this just libffi?

This might sound awfully familiar to [libffi](http://sourceware.org/libffi/).
After all, libffi provides `ffi_type`, which is used to describe the types of
values passed around by functions.  However, `ffi_type` does not contain all of
the information we might need to know about a C type.  Since libffi is focused
on calling conventions and ABIs, `ffi_type` focuses on just the information
needed to successfully use a value of that type as a parameter or result of a
function call.

Yardarm and libffi type descriptors are orthogonal.  In fact, one of the (more
immediate) plans for Yardarm is to allow you to automatically generate
`ffi_type` descriptors from a Yardarm type descriptor.


## How?

Coming soon.  The API is in flux; check back in a few days.

#ifndef CALLS_LIB_H
#define CALLS_LIB_H

namespace calls {

void call1(int a);

void call2(int a);

void call3(int a);

} // namespace

extern "C" {

void calls_call1(int a); 

void calls_call2(int a);

void calls_call3(int a);

} // extern C

#endif


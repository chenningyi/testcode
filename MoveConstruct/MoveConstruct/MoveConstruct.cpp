// MoveConstruct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "atlstr.h"


class SmallMeta {
public:
  SmallMeta() {
    wprintf(L"SmalMeta default Construct.  %x\r", this);
  }

  SmallMeta(wchar_t* msg) {
    msg_ = msg;
    wprintf(L"SmalMeta Construct. %s, %x\r", (LPCWSTR)msg_, this);
  }

  //SmalMeta(const SmalMeta& other) {
  //  msg_ = other.msg_;

  //  wprintf(L"SmalMeta copy Construct. %s, %x\r", (LPCWSTR)msg_, this);
  //}

  ~SmallMeta() {
    wprintf(L"SmalMeta destruct. %s, %x\r", (LPCWSTR)msg_, this);
  }

  void SetMsg(wchar_t* msg) {
    msg_ = msg;
  }


private:
  CString msg_;
};


class Meta {
public:
  Meta() {
    wchar_msg_ = NULL;
    wprintf(L"== Meta default Construct.  %x\r\n", this);
  }

  Meta(wchar_t* msg) {
    msg_ = msg;
    wchar_msg_ = NULL;

    wprintf(L"== Meta Construct. %s, %x\r\n", (LPCWSTR)msg_, this);
  }

  Meta(const Meta& other) {
    msg_ = other.msg_;
    //wchar_msg_ = NULL;

    wprintf(L"== Meta copy Construct. %s, %x\r\n", (LPCWSTR)msg_, this);
  }

  ~Meta() {
    wprintf(L"== Meta destruct. %s, %x\r\n", (LPCWSTR)msg_, this);
  }

  Meta& operator=(const Meta& other) {
    wchar_msg_ = other.wchar_msg_;
    return *this;
  }

  void SetMsg(wchar_t* msg) {
    msg_ = msg;
  }

  void SetCharMsg(wchar_t* msg) {
    wchar_msg_ = msg;
  }

private:
  CString msg_;
  wchar_t* wchar_msg_;
  SmallMeta small_meta_;
};

Meta GetMeta() {
  Meta a(L"in testfun");
  a.SetCharMsg(L"test msg");
  
  return a;
}

void TestFunWithParame(const Meta& a) {
  //a.SetMsg(L"in TestFunWithParame");
}


void TestFunction1()
{
  TestFunWithParame(GetMeta());
  
  
  
  const Meta aa(L"111");
  //aa.SetCharMsg(L"test char msg");
  Meta bb(aa);

  bb = aa;


  //Meta a(L"in caller");
  //a = TestFun();
  //a.SetMsg(L"in caller");

  Meta a = GetMeta();
  a.SetMsg(L"in caller");
}



#define _THROW0()	throw ()

namespace std {

// TEMPLATE CLASS auto_ptr
template<class _Ty>
class auto_ptr;

template<class _Ty>
struct auto_ptr_ref
{	// proxy reference for auto_ptr copying
  explicit auto_ptr_ref(_Ty *_Right)
    : _Ref(_Right)
  {	// construct from generic pointer to auto_ptr ptr
  }

  _Ty *_Ref;	// generic pointer to auto_ptr ptr
};

template<class _Ty>
class auto_ptr
{	// wrap an object pointer to ensure destruction
public:
  typedef _Ty element_type;

  explicit auto_ptr(_Ty *_Ptr = 0) _THROW0()
    : _Myptr(_Ptr)
  {	// construct from object pointer
  }

  auto_ptr(auto_ptr<_Ty>& _Right) _THROW0()
    : _Myptr(_Right.release())
  {	// construct by assuming pointer from _Right auto_ptr
  }

  auto_ptr(auto_ptr_ref<_Ty> _Right) _THROW0()
  {	// construct by assuming pointer from _Right auto_ptr_ref
    _Ty *_Ptr = _Right._Ref;
    _Right._Ref = 0;	// release old
    _Myptr = _Ptr;	// reset this
  }

  template<class _Other>
  operator auto_ptr<_Other>() _THROW0()
  {	// convert to compatible auto_ptr
    return (auto_ptr<_Other>(*this));
  }

  template<class _Other>
  operator auto_ptr_ref<_Other>() _THROW0()
  {	// convert to compatible auto_ptr_ref
    _Other *_Cvtptr = _Myptr;	// test implicit conversion
    auto_ptr_ref<_Other> _Ans(_Cvtptr);
    _Myptr = 0;	// pass ownership to auto_ptr_ref
    return (_Ans);
  }


  template<class _Other>
  auto_ptr<_Ty>& operator=(auto_ptr<_Other>& _Right) _THROW0()
  {	// assign compatible _Right (assume pointer)
    reset(_Right.release());
    return (*this);
  }

  template<class _Other>
  auto_ptr(auto_ptr<_Other>& _Right) _THROW0()
    : _Myptr(_Right.release())
  {	// construct by assuming pointer from _Right
  }

  auto_ptr<_Ty>& operator=(auto_ptr<_Ty>& _Right) _THROW0()
  {	// assign compatible _Right (assume pointer)
    reset(_Right.release());
    return (*this);
  }

  auto_ptr<_Ty>& operator=(auto_ptr_ref<_Ty> _Right) _THROW0()
  {	// assign compatible _Right._Ref (assume pointer)
    _Ty *_Ptr = _Right._Ref;
    _Right._Ref = 0;	// release old
    reset(_Ptr);	// set new
    return (*this);
  }

  ~auto_ptr()
  {	// destroy the object
    delete _Myptr;
  }

  _Ty& operator*() const _THROW0()
  {	// return designated value

#if _HAS_ITERATOR_DEBUGGING
    if (_Myptr == 0)
      _DEBUG_ERROR("auto_ptr not dereferencable");
#endif /* _HAS_ITERATOR_DEBUGGING */

    __analysis_assume(_Myptr);

    return (*get());
  }

  _Ty *operator->() const _THROW0()
  {	// return pointer to class object

#if _HAS_ITERATOR_DEBUGGING
    if (_Myptr == 0)
      _DEBUG_ERROR("auto_ptr not dereferencable");
#endif /* _HAS_ITERATOR_DEBUGGING */

    return (get());
  }

  _Ty *get() const _THROW0()
  {	// return wrapped pointer
    return (_Myptr);
  }

  _Ty *release() _THROW0()
  {	// return wrapped pointer and give up ownership
    _Ty *_Tmp = _Myptr;
    _Myptr = 0;
    return (_Tmp);
  }

  void reset(_Ty* _Ptr = 0)
  {	// destroy designated object and store new pointer
    if (_Ptr != _Myptr)
      delete _Myptr;
    _Myptr = _Ptr;
  }

private:
  _Ty *_Myptr;	// the wrapped object pointer
};

}

std::auto_ptr<char> GetPoint() {
  std::auto_ptr<char> pt;
  pt.reset("aaaa");
  return pt;
}


void TestFunction2()
{
  std::auto_ptr<char> cc(GetPoint());
  std::auto_ptr<char> dd(cc);

  //std::auto_ptr<char> cc(GetPoint());
  //cc.reset(NULL);
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestFunction1();
  TestFunction2();
  return 0;
}


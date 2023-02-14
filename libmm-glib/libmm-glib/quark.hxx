#ifndef _GLIBMM_QUARK_H
#define _GLIBMM_QUARK_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>

namespace Glib
{

  class GLIBMM_API QueryQuark
  {
  public:
    QueryQuark (const GQuark& q);
    QueryQuark (const ustring& s);
    QueryQuark (const char* s);

    ~QueryQuark () noexcept {}

    auto
    operator= (const QueryQuark& q) -> QueryQuark&;
    operator ustring () const;

    operator GQuark () const
    {
      return quark_;
    }

    auto
    id () const -> GQuark
    {
      return quark_;
    }

  private:
    GQuark quark_;
  };

  class GLIBMM_API Quark : public QueryQuark
  {
  public:
    Quark (const ustring& s);
    Quark (const char* s);
    ~Quark () noexcept;
  };

  inline auto
  operator== (const QueryQuark& a, const QueryQuark& b) -> bool
  {
    return a.id () == b.id ();
  }

  inline auto
  operator!= (const QueryQuark& a, const QueryQuark& b) -> bool
  {
    return a.id () != b.id ();
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  extern GLIBMM_API GQuark quark_;
  extern GLIBMM_API GQuark quark_cpp_wrapper_deleted_;
#endif

} // namespace Glib

#endif

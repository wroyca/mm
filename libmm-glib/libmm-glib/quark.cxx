

#include <libmm-glib/quark.hxx>

namespace Glib
{

  QueryQuark::QueryQuark (const GQuark& q)
    : quark_ (q)
  {
  }

  QueryQuark::QueryQuark (const ustring& s)
    : quark_ (g_quark_try_string (s.c_str ()))
  {
  }

  QueryQuark::QueryQuark (const char* s)
    : quark_ (g_quark_try_string (s))
  {
  }

  auto
  QueryQuark::operator= (const QueryQuark& q) -> QueryQuark& = default;

  QueryQuark::operator ustring () const
  {
    return {g_quark_to_string (quark_)};
  }

  Quark::Quark (const ustring& s)
    : QueryQuark (g_quark_from_string (s.c_str ()))
  {
  }

  Quark::Quark (const char* s)
    : QueryQuark (g_quark_from_string (s))
  {
  }

  Quark::~Quark () noexcept = default;

  GQuark quark_ = 0;
  GQuark quark_cpp_wrapper_deleted_ = 0;

} // namespace Glib

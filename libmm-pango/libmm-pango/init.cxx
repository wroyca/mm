

#include <libmm-glib/init.hxx>
#include <libmm-pango/wrap_init.hxx>

namespace Pango
{

  auto
  init () -> void
  {
    Glib::init ();
    wrap_init ();
  }

} // namespace Pango

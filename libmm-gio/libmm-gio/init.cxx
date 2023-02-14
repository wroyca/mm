

#include <libmm-gio/init.hxx>
#include <libmm-glib/init.hxx>

namespace Gio
{

  auto
  init () -> void
  {
    static bool s_init = false;
    if (!s_init)
    {
      Glib::init ();
      wrap_init ();
      s_init = true;
    }
  }

} // namespace Gio



#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/color.hxx>
#include <libmm-pango/color_p.hxx>

#include <cstring>

namespace Pango
{

  auto
  _pango_color_new () -> PangoColor*
  {
    return g_new (PangoColor, 1);
  }

  Color::operator bool () const
  {
    return gobj () != nullptr;
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoColor* object) -> Pango::Color&
  {
    return *reinterpret_cast<Pango::Color*> (object);
  }

  auto
  wrap (const PangoColor* object) -> const Pango::Color&
  {
    return *reinterpret_cast<const Pango::Color*> (object);
  }

} // namespace Glib

namespace Pango
{

  Color::Color (const Color& other) noexcept = default;

  auto
  Color::operator= (const Color& other) noexcept -> Color& = default;

  Color::Color (Color&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
  }

  auto
  Color::operator= (Color&& other) noexcept -> Color&
  {
    gobject_ = std::move (other.gobject_);
    return *this;
  }

  auto
  Color::get_type () -> GType
  {
    return pango_color_get_type ();
  }

  Color::Color ()
  {
    std::memset (&gobject_, 0, sizeof (PangoColor));
  }

  Color::Color (const PangoColor* gobject)
  {
    if (gobject)
      gobject_ = *gobject;
    else
      std::memset (&gobject_, 0, sizeof (PangoColor));
  }

  auto
  Color::get_red () const -> guint16
  {
    return gobj ()->red;
  }

  auto
  Color::get_green () const -> guint16
  {
    return gobj ()->green;
  }

  auto
  Color::get_blue () const -> guint16
  {
    return gobj ()->blue;
  }

  auto
  Color::set_red (const guint16& value) -> void
  {
    gobj ()->red = value;
  }

  auto
  Color::set_green (const guint16& value) -> void
  {
    gobj ()->green = value;
  }

  auto
  Color::set_blue (const guint16& value) -> void
  {
    gobj ()->blue = value;
  }

  auto
  Color::parse (const Glib::ustring& spec) -> bool
  {
    return pango_color_parse (gobj (), spec.c_str ());
  }

  auto
  Color::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        pango_color_to_string (gobj ()));
  }

} // namespace Pango

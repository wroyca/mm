// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/cursor_p.hxx>

#include <gdk/gdk.h>

namespace Gdk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkCursor* object, bool take_copy) -> Glib::RefPtr<Gdk::Cursor>
  {
    return Glib::make_refptr_for_instance<Gdk::Cursor> (
        dynamic_cast<Gdk::Cursor*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Cursor_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gdk_cursor_get_type ();
    }

    return *this;
  }

  auto
  Cursor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Cursor ((GdkCursor*) object);
  }

  auto
  Cursor::gobj_copy () -> GdkCursor*
  {
    reference ();
    return gobj ();
  }

  Cursor::Cursor (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Cursor::Cursor (GdkCursor* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Cursor::Cursor (Cursor&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Cursor::operator= (Cursor&& src) noexcept -> Cursor&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  Cursor::~Cursor () noexcept {}

  Cursor::CppClassType Cursor::cursor_class_;

  auto
  Cursor::get_type () -> GType
  {
    return cursor_class_.init ().get_type ();
  }

  auto
  Cursor::get_base_type () -> GType
  {
    return gdk_cursor_get_type ();
  }

  auto
  Cursor::create (const Glib::RefPtr<const Texture>& texture,
                  int hotspot_x,
                  int hotspot_y,
                  const Glib::RefPtr<Cursor>& fallback) -> Glib::RefPtr<Cursor>
  {
    return Glib::wrap (gdk_cursor_new_from_texture (
        const_cast<GdkTexture*> (Glib::unwrap (texture)),
        hotspot_x,
        hotspot_y,
        Glib::unwrap (fallback)));
  }

  auto
  Cursor::create (const Glib::ustring& name,
                  const Glib::RefPtr<Cursor>& fallback) -> Glib::RefPtr<Cursor>
  {
    return Glib::wrap (
        gdk_cursor_new_from_name (name.c_str (), Glib::unwrap (fallback)));
  }

  auto
  Cursor::get_fallback () -> Glib::RefPtr<Cursor>
  {
    auto retvalue = Glib::wrap (gdk_cursor_get_fallback (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Cursor::get_fallback () const -> Glib::RefPtr<const Cursor>
  {
    return const_cast<Cursor*> (this)->get_fallback ();
  }

  auto
  Cursor::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_cursor_get_name (const_cast<GdkCursor*> (gobj ())));
  }

  auto
  Cursor::get_texture () -> Glib::RefPtr<Texture>
  {
    auto retvalue = Glib::wrap (gdk_cursor_get_texture (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Cursor::get_texture () const -> Glib::RefPtr<const Texture>
  {
    return const_cast<Cursor*> (this)->get_texture ();
  }

  auto
  Cursor::get_hotspot_x () const -> int
  {
    return gdk_cursor_get_hotspot_x (const_cast<GdkCursor*> (gobj ()));
  }

  auto
  Cursor::get_hotspot_y () const -> int
  {
    return gdk_cursor_get_hotspot_y (const_cast<GdkCursor*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Cursor>>::value,
      "Type Glib::RefPtr<Cursor> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Cursor::property_fallback () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Cursor>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Cursor>> (this,
                                                               "fallback");
  }

  auto
  Cursor::property_hotspot_x () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "hotspot-x");
  }

  auto
  Cursor::property_hotspot_y () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "hotspot-y");
  }

  auto
  Cursor::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Texture>>::value,
      "Type Glib::RefPtr<Texture> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Cursor::property_texture () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Texture>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Texture>> (this,
                                                                "texture");
  }

} // namespace Gdk

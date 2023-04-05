// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/cursor.hxx>
#include <libmm/gdk/cursor_p.hxx>

#include <gdk/gdk.h>

namespace gdk
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GdkCursor* object, bool take_copy) -> glib::RefPtr<gdk::Cursor>
  {
    return glib::make_refptr_for_instance<gdk::Cursor> (
        dynamic_cast<gdk::Cursor*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Cursor_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gdk_cursor_get_type ();
    }

    return *this;
  }

  auto
  Cursor_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Cursor ((GdkCursor*) object);
  }

  auto
  Cursor::gobj_copy () -> GdkCursor*
  {
    reference ();
    return gobj ();
  }

  Cursor::Cursor (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Cursor::Cursor (GdkCursor* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Cursor::Cursor (Cursor&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Cursor::operator= (Cursor&& src) noexcept -> Cursor&
  {
    glib::Object::operator= (std::move (src));
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
  Cursor::create (const glib::RefPtr<const Texture>& texture,
                  int hotspot_x,
                  int hotspot_y,
                  const glib::RefPtr<Cursor>& fallback) -> glib::RefPtr<Cursor>
  {
    return glib::wrap (gdk_cursor_new_from_texture (
        const_cast<GdkTexture*> (glib::unwrap (texture)),
        hotspot_x,
        hotspot_y,
        glib::unwrap (fallback)));
  }

  auto
  Cursor::create (const glib::ustring& name,
                  const glib::RefPtr<Cursor>& fallback) -> glib::RefPtr<Cursor>
  {
    return glib::wrap (
        gdk_cursor_new_from_name (name.c_str (), glib::unwrap (fallback)));
  }

  auto
  Cursor::get_fallback () -> glib::RefPtr<Cursor>
  {
    auto retvalue = glib::wrap (gdk_cursor_get_fallback (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Cursor::get_fallback () const -> glib::RefPtr<const Cursor>
  {
    return const_cast<Cursor*> (this)->get_fallback ();
  }

  auto
  Cursor::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_cursor_get_name (const_cast<GdkCursor*> (gobj ())));
  }

  auto
  Cursor::get_texture () -> glib::RefPtr<Texture>
  {
    auto retvalue = glib::wrap (gdk_cursor_get_texture (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Cursor::get_texture () const -> glib::RefPtr<const Texture>
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Cursor>>::value,
      "Type glib::RefPtr<Cursor> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Cursor::property_fallback () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Cursor>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Cursor>> (this,
                                                               "fallback");
  }

  auto
  Cursor::property_hotspot_x () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "hotspot-x");
  }

  auto
  Cursor::property_hotspot_y () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "hotspot-y");
  }

  auto
  Cursor::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Texture>>::value,
      "Type glib::RefPtr<Texture> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Cursor::property_texture () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Texture>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Texture>> (this,
                                                                "texture");
  }

} // namespace gdk

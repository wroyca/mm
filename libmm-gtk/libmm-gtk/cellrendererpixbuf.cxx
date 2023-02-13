


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/cellrendererpixbuf.hxx>
#include <libmm-gtk/cellrendererpixbuf_p.hxx>


/*
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <gtk/gtk.h>

namespace Gtk
{

auto CellRendererPixbuf::_property_renderable() -> Glib::PropertyProxy_Base
{
  return property_pixbuf();
}

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererPixbuf* object, const bool take_copy) -> Gtk::CellRendererPixbuf*
{
  return dynamic_cast<Gtk::CellRendererPixbuf *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererPixbuf_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererPixbuf_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_pixbuf_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellRendererPixbuf_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererPixbuf_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererPixbuf((GtkCellRendererPixbuf*)o));

}


/* The implementation: */

CellRendererPixbuf::CellRendererPixbuf(const Glib::ConstructParams& construct_params)
: CellRenderer(construct_params)
{
  }

CellRendererPixbuf::CellRendererPixbuf(GtkCellRendererPixbuf* castitem)
: CellRenderer((GtkCellRenderer*)castitem)
{
  }


CellRendererPixbuf::CellRendererPixbuf(CellRendererPixbuf&& src) noexcept
: CellRenderer(std::move(src))
{}

auto CellRendererPixbuf::operator=(CellRendererPixbuf&& src) noexcept -> CellRendererPixbuf&
{
  CellRenderer::operator=(std::move(src));
  return *this;
}

CellRendererPixbuf::~CellRendererPixbuf() noexcept
{
  destroy_();
}

CellRendererPixbuf::CppClassType CellRendererPixbuf::cellrendererpixbuf_class_; // initialize static member

auto CellRendererPixbuf::get_type() -> GType
{
  return cellrendererpixbuf_class_.init().get_type();
}


auto CellRendererPixbuf::get_base_type() -> GType
{
  return gtk_cell_renderer_pixbuf_get_type();
}


CellRendererPixbuf::CellRendererPixbuf()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
CellRenderer(Glib::ConstructParams(cellrendererpixbuf_class_.init()))
{


}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Pixbuf>>::value,
  "Type Glib::RefPtr<Gdk::Pixbuf> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererPixbuf::property_pixbuf() -> Glib::PropertyProxy_WriteOnly< Glib::RefPtr<Gdk::Pixbuf> >
{
  return {this, "pixbuf"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Pixbuf>>::value,
  "Type Glib::RefPtr<Gdk::Pixbuf> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererPixbuf::property_pixbuf_expander_open() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >
{
  return {this, "pixbuf-expander-open"};
}

auto CellRendererPixbuf::property_pixbuf_expander_open() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >
{
  return {this, "pixbuf-expander-open"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Pixbuf>>::value,
  "Type Glib::RefPtr<Gdk::Pixbuf> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererPixbuf::property_pixbuf_expander_closed() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >
{
  return {this, "pixbuf-expander-closed"};
}

auto CellRendererPixbuf::property_pixbuf_expander_closed() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >
{
  return {this, "pixbuf-expander-closed"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<IconSize>::value,
  "Type Gtk::IconSize cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererPixbuf::property_icon_size() -> Glib::PropertyProxy<IconSize>
{
  return {this, "icon-size"};
}

auto CellRendererPixbuf::property_icon_size() const -> Glib::PropertyProxy_ReadOnly<IconSize>
{
  return {this, "icon-size"};
}

auto CellRendererPixbuf::property_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "icon-name"};
}

auto CellRendererPixbuf::property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "icon-name"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::Icon>>::value,
  "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererPixbuf::property_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >
{
  return {this, "gicon"};
}

auto CellRendererPixbuf::property_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >
{
  return {this, "gicon"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Texture>>::value,
  "Type Glib::RefPtr<Gdk::Texture> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererPixbuf::property_texture() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Texture> >
{
  return {this, "texture"};
}

auto CellRendererPixbuf::property_texture() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Texture> >
{
  return {this, "texture"};
}


} // namespace Gtk


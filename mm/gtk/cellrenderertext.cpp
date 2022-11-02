// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/cellrenderertext.hpp>
#include <mm/gtk/private/cellrenderertext_p.hpp>


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

auto CellRendererText::_property_renderable() -> Glib::PropertyProxy_Base
{
  return property_text();
}

auto CellRendererText::edited (const Glib::ustring &path, const Glib::ustring &new_text) -> void
{
  g_signal_emit_by_name(gobj(), "edited", path.c_str(), new_text.c_str());
}

} // namespace Gtk


namespace
{


auto CellRendererText_signal_edited_callback (
  GtkCellRendererText *self, const gchar *p0, const gchar *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&, const Glib::ustring&)>;

  auto obj = dynamic_cast<CellRendererText*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::convert_const_gchar_ptr_to_ustring(p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo CellRendererText_signal_edited_info =
{
  "edited",
  (GCallback) &CellRendererText_signal_edited_callback,
  (GCallback) &CellRendererText_signal_edited_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererText* object, bool take_copy) -> Gtk::CellRendererText*
{
  return dynamic_cast<Gtk::CellRendererText *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererText_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererText_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_text_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellRendererText_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->edited = &edited_callback;
}


auto CellRendererText_Class::edited_callback (
  GtkCellRendererText *self, const gchar *p0, const gchar *p1) -> void
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_edited(Glib::convert_const_gchar_ptr_to_ustring(p0)
, Glib::convert_const_gchar_ptr_to_ustring(p1)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->edited)
    (*base->edited)(self, p0, p1);
}


auto CellRendererText_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererText((GtkCellRendererText*)(o)));

}


/* The implementation: */

CellRendererText::CellRendererText(const Glib::ConstructParams& construct_params)
:
  Gtk::CellRenderer(construct_params)
{
  }

CellRendererText::CellRendererText(GtkCellRendererText* castitem)
:
  Gtk::CellRenderer((GtkCellRenderer*)(castitem))
{
  }


CellRendererText::CellRendererText(CellRendererText&& src) noexcept
: Gtk::CellRenderer(std::move(src))
{}

auto CellRendererText::operator=(CellRendererText&& src) noexcept -> CellRendererText&
{
  Gtk::CellRenderer::operator=(std::move(src));
  return *this;
}

CellRendererText::~CellRendererText() noexcept
{
  destroy_();
}

CellRendererText::CppClassType CellRendererText::cellrenderertext_class_; // initialize static member

auto CellRendererText::get_type() -> GType
{
  return cellrenderertext_class_.init().get_type();
}


auto CellRendererText::get_base_type() -> GType
{
  return gtk_cell_renderer_text_get_type();
}


CellRendererText::CellRendererText()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::CellRenderer(Glib::ConstructParams(cellrenderertext_class_.init()))
{


}

auto CellRendererText::set_fixed_height_from_font (int number_of_rows) -> void
{
  gtk_cell_renderer_text_set_fixed_height_from_font(gobj(), number_of_rows);
}


auto CellRendererText::signal_edited() -> Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&)>
{
  return Glib::SignalProxy<void(const Glib::ustring&, const Glib::ustring&) >(this, &CellRendererText_signal_edited_info);
}


auto CellRendererText::property_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "text");
}

auto CellRendererText::property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "text");
}

auto CellRendererText::property_markup() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "markup");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
  "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_attributes() -> Glib::PropertyProxy< Pango::AttrList >
{
  return Glib::PropertyProxy< Pango::AttrList >(this, "attributes");
}

auto CellRendererText::property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >
{
  return Glib::PropertyProxy_ReadOnly< Pango::AttrList >(this, "attributes");
}

auto CellRendererText::property_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "background");
}

auto CellRendererText::property_foreground() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "foreground");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return Glib::PropertyProxy< Gdk::RGBA >(this, "background-rgba");
}

auto CellRendererText::property_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return Glib::PropertyProxy_ReadOnly< Gdk::RGBA >(this, "background-rgba");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_foreground_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return Glib::PropertyProxy< Gdk::RGBA >(this, "foreground-rgba");
}

auto CellRendererText::property_foreground_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return Glib::PropertyProxy_ReadOnly< Gdk::RGBA >(this, "foreground-rgba");
}

auto CellRendererText::property_font() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "font");
}

auto CellRendererText::property_font() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "font");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::FontDescription>::value,
  "Type Pango::FontDescription cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_font_desc() -> Glib::PropertyProxy< Pango::FontDescription >
{
  return Glib::PropertyProxy< Pango::FontDescription >(this, "font-desc");
}

auto CellRendererText::property_font_desc() const -> Glib::PropertyProxy_ReadOnly< Pango::FontDescription >
{
  return Glib::PropertyProxy_ReadOnly< Pango::FontDescription >(this, "font-desc");
}

auto CellRendererText::property_family() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "family");
}

auto CellRendererText::property_family() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "family");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Style>::value,
  "Type Pango::Style cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_style() -> Glib::PropertyProxy< Pango::Style >
{
  return Glib::PropertyProxy< Pango::Style >(this, "style");
}

auto CellRendererText::property_style() const -> Glib::PropertyProxy_ReadOnly< Pango::Style >
{
  return Glib::PropertyProxy_ReadOnly< Pango::Style >(this, "style");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Variant>::value,
  "Type Pango::Variant cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_variant() -> Glib::PropertyProxy< Pango::Variant >
{
  return Glib::PropertyProxy< Pango::Variant >(this, "variant");
}

auto CellRendererText::property_variant() const -> Glib::PropertyProxy_ReadOnly< Pango::Variant >
{
  return Glib::PropertyProxy_ReadOnly< Pango::Variant >(this, "variant");
}

auto CellRendererText::property_weight() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "weight");
}

auto CellRendererText::property_weight() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "weight");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Stretch>::value,
  "Type Pango::Stretch cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_stretch() -> Glib::PropertyProxy< Pango::Stretch >
{
  return Glib::PropertyProxy< Pango::Stretch >(this, "stretch");
}

auto CellRendererText::property_stretch() const -> Glib::PropertyProxy_ReadOnly< Pango::Stretch >
{
  return Glib::PropertyProxy_ReadOnly< Pango::Stretch >(this, "stretch");
}

auto CellRendererText::property_size() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "size");
}

auto CellRendererText::property_size() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "size");
}

auto CellRendererText::property_size_points() -> Glib::PropertyProxy< double >
{
  return Glib::PropertyProxy< double >(this, "size-points");
}

auto CellRendererText::property_size_points() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "size-points");
}

auto CellRendererText::property_scale() -> Glib::PropertyProxy< double >
{
  return Glib::PropertyProxy< double >(this, "scale");
}

auto CellRendererText::property_scale() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "scale");
}

auto CellRendererText::property_editable() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "editable");
}

auto CellRendererText::property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "editable");
}

auto CellRendererText::property_strikethrough() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "strikethrough");
}

auto CellRendererText::property_strikethrough() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "strikethrough");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Underline>::value,
  "Type Pango::Underline cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_underline() -> Glib::PropertyProxy< Pango::Underline >
{
  return Glib::PropertyProxy< Pango::Underline >(this, "underline");
}

auto CellRendererText::property_underline() const -> Glib::PropertyProxy_ReadOnly< Pango::Underline >
{
  return Glib::PropertyProxy_ReadOnly< Pango::Underline >(this, "underline");
}

auto CellRendererText::property_rise() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "rise");
}

auto CellRendererText::property_rise() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "rise");
}

auto CellRendererText::property_language() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "language");
}

auto CellRendererText::property_language() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "language");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::EllipsizeMode>::value,
  "Type Pango::EllipsizeMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_ellipsize() -> Glib::PropertyProxy< Pango::EllipsizeMode >
{
  return Glib::PropertyProxy< Pango::EllipsizeMode >(this, "ellipsize");
}

auto CellRendererText::property_ellipsize() const -> Glib::PropertyProxy_ReadOnly< Pango::EllipsizeMode >
{
  return Glib::PropertyProxy_ReadOnly< Pango::EllipsizeMode >(this, "ellipsize");
}

auto CellRendererText::property_width_chars() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "width-chars");
}

auto CellRendererText::property_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "width-chars");
}

auto CellRendererText::property_max_width_chars() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "max-width-chars");
}

auto CellRendererText::property_max_width_chars() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "max-width-chars");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::WrapMode>::value,
  "Type Pango::WrapMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_wrap_mode() -> Glib::PropertyProxy< Pango::WrapMode >
{
  return Glib::PropertyProxy< Pango::WrapMode >(this, "wrap-mode");
}

auto CellRendererText::property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< Pango::WrapMode >
{
  return Glib::PropertyProxy_ReadOnly< Pango::WrapMode >(this, "wrap-mode");
}

auto CellRendererText::property_wrap_width() -> Glib::PropertyProxy< int >
{
  return Glib::PropertyProxy< int >(this, "wrap-width");
}

auto CellRendererText::property_wrap_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "wrap-width");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Alignment>::value,
  "Type Pango::Alignment cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererText::property_alignment() -> Glib::PropertyProxy< Pango::Alignment >
{
  return Glib::PropertyProxy< Pango::Alignment >(this, "alignment");
}

auto CellRendererText::property_alignment() const -> Glib::PropertyProxy_ReadOnly< Pango::Alignment >
{
  return Glib::PropertyProxy_ReadOnly< Pango::Alignment >(this, "alignment");
}

auto CellRendererText::property_background_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "background-set");
}

auto CellRendererText::property_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "background-set");
}

auto CellRendererText::property_foreground_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "foreground-set");
}

auto CellRendererText::property_foreground_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "foreground-set");
}

auto CellRendererText::property_family_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "family-set");
}

auto CellRendererText::property_family_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "family-set");
}

auto CellRendererText::property_style_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "style-set");
}

auto CellRendererText::property_style_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "style-set");
}

auto CellRendererText::property_variant_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "variant-set");
}

auto CellRendererText::property_variant_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "variant-set");
}

auto CellRendererText::property_weight_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "weight-set");
}

auto CellRendererText::property_weight_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "weight-set");
}

auto CellRendererText::property_stretch_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "stretch-set");
}

auto CellRendererText::property_stretch_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "stretch-set");
}

auto CellRendererText::property_size_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "size-set");
}

auto CellRendererText::property_size_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "size-set");
}

auto CellRendererText::property_scale_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "scale-set");
}

auto CellRendererText::property_scale_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "scale-set");
}

auto CellRendererText::property_editable_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "editable-set");
}

auto CellRendererText::property_editable_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "editable-set");
}

auto CellRendererText::property_strikethrough_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "strikethrough-set");
}

auto CellRendererText::property_strikethrough_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "strikethrough-set");
}

auto CellRendererText::property_underline_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "underline-set");
}

auto CellRendererText::property_underline_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "underline-set");
}

auto CellRendererText::property_rise_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "rise-set");
}

auto CellRendererText::property_rise_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "rise-set");
}

auto CellRendererText::property_language_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "language-set");
}

auto CellRendererText::property_language_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "language-set");
}

auto CellRendererText::property_ellipsize_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "ellipsize-set");
}

auto CellRendererText::property_ellipsize_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "ellipsize-set");
}

auto CellRendererText::property_single_paragraph_mode() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "single-paragraph-mode");
}

auto CellRendererText::property_single_paragraph_mode() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "single-paragraph-mode");
}

auto CellRendererText::property_align_set() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "align-set");
}

auto CellRendererText::property_align_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "align-set");
}

auto CellRendererText::property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "placeholder-text");
}

auto CellRendererText::property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "placeholder-text");
}


auto Gtk::CellRendererText::on_edited (
  const Glib::ustring &path, const Glib::ustring &new_text) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->edited)
    (*base->edited)(gobj(),path.c_str(),new_text.c_str());
}


} // namespace Gtk



// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrenderertext.hxx>
  #include <libmm/gtk/cellrenderertext_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  auto
  CellRendererText::_property_renderable () -> glib::PropertyProxy_Base
  {
    return property_text ();
  }

  auto
  CellRendererText::edited (const glib::ustring& path,
                            const glib::ustring& new_text) -> void
  {
    g_signal_emit_by_name (gobj (), "edited", path.c_str (), new_text.c_str ());
  }

} // namespace gtk

namespace
{

  static auto
  CellRendererText_signal_edited_callback (GtkCellRendererText* self,
                                           const gchar* p0,
                                           const gchar* p1,
                                           void* data) -> void
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const glib::ustring&, const glib::ustring&)>;

    auto obj = dynamic_cast<CellRendererText*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              glib::convert_const_gchar_ptr_to_ustring (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellRendererText_signal_edited_info = {
      "edited",
      (GCallback) &CellRendererText_signal_edited_callback,
      (GCallback) &CellRendererText_signal_edited_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkCellRendererText* object, bool take_copy) -> gtk::CellRendererText*
  {
    return dynamic_cast<gtk::CellRendererText*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererText_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererText_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_text_get_type ());
    }

    return *this;
  }

  auto
  CellRendererText_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->edited = &edited_callback;
  }

  auto
  CellRendererText_Class::edited_callback (GtkCellRendererText* self,
                                           const gchar* p0,
                                           const gchar* p1) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_edited (glib::convert_const_gchar_ptr_to_ustring (p0),
                          glib::convert_const_gchar_ptr_to_ustring (p1));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->edited)
      (*base->edited) (self, p0, p1);
  }

  auto
  CellRendererText_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererText ((GtkCellRendererText*) (o)));
  }

  CellRendererText::CellRendererText (
      const glib::ConstructParams& construct_params)
    : gtk::CellRenderer (construct_params)
  {
  }

  CellRendererText::CellRendererText (GtkCellRendererText* castitem)
    : gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererText::CellRendererText (CellRendererText&& src) noexcept
    : gtk::CellRenderer (std::move (src))
  {
  }

  auto
  CellRendererText::operator= (CellRendererText&& src) noexcept -> CellRendererText&
  {
    gtk::CellRenderer::operator= (std::move (src));
    return *this;
  }

  CellRendererText::~CellRendererText () noexcept
  {
    destroy_ ();
  }

  CellRendererText::CppClassType CellRendererText::cellrenderertext_class_;

  auto
  CellRendererText::get_type () -> GType
  {
    return cellrenderertext_class_.init ().get_type ();
  }

  auto
  CellRendererText::get_base_type () -> GType
  {
    return gtk_cell_renderer_text_get_type ();
  }

  CellRendererText::CellRendererText ()
    : glib::ObjectBase (nullptr),
      gtk::CellRenderer (
          glib::ConstructParams (cellrenderertext_class_.init ()))
  {
  }

  auto
  CellRendererText::set_fixed_height_from_font (int number_of_rows) -> void
  {
    gtk_cell_renderer_text_set_fixed_height_from_font (gobj (), number_of_rows);
  }

  auto
  CellRendererText::signal_edited () -> glib::SignalProxy<void (const glib::ustring&, const glib::ustring&)>
  {
    return glib::SignalProxy<void (const glib::ustring&,
                                   const glib::ustring&)> (
        this,
        &CellRendererText_signal_edited_info);
  }

  auto
  CellRendererText::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text");
  }

  auto
  CellRendererText::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text");
  }

  auto
  CellRendererText::property_markup () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "markup");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::AttrList>::value,
      "Type pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_attributes () -> glib::PropertyProxy<pango::AttrList>
  {
    return glib::PropertyProxy<pango::AttrList> (this, "attributes");
  }

  auto
  CellRendererText::property_attributes () const -> glib::PropertyProxy_ReadOnly<pango::AttrList>
  {
    return glib::PropertyProxy_ReadOnly<pango::AttrList> (this, "attributes");
  }

  auto
  CellRendererText::property_background () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "background");
  }

  auto
  CellRendererText::property_foreground () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "foreground");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_background_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "background-rgba");
  }

  auto
  CellRendererText::property_background_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "background-rgba");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_foreground_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "foreground-rgba");
  }

  auto
  CellRendererText::property_foreground_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "foreground-rgba");
  }

  auto
  CellRendererText::property_font () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "font");
  }

  auto
  CellRendererText::property_font () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "font");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::FontDescription>::value,
      "Type pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_font_desc () -> glib::PropertyProxy<pango::FontDescription>
  {
    return glib::PropertyProxy<pango::FontDescription> (this, "font-desc");
  }

  auto
  CellRendererText::property_font_desc () const -> glib::PropertyProxy_ReadOnly<pango::FontDescription>
  {
    return glib::PropertyProxy_ReadOnly<pango::FontDescription> (this,
                                                                 "font-desc");
  }

  auto
  CellRendererText::property_family () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "family");
  }

  auto
  CellRendererText::property_family () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "family");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Style>::value,
      "Type pango::Style cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_style () -> glib::PropertyProxy<pango::Style>
  {
    return glib::PropertyProxy<pango::Style> (this, "style");
  }

  auto
  CellRendererText::property_style () const -> glib::PropertyProxy_ReadOnly<pango::Style>
  {
    return glib::PropertyProxy_ReadOnly<pango::Style> (this, "style");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Variant>::value,
      "Type pango::Variant cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_variant () -> glib::PropertyProxy<pango::Variant>
  {
    return glib::PropertyProxy<pango::Variant> (this, "variant");
  }

  auto
  CellRendererText::property_variant () const -> glib::PropertyProxy_ReadOnly<pango::Variant>
  {
    return glib::PropertyProxy_ReadOnly<pango::Variant> (this, "variant");
  }

  auto
  CellRendererText::property_weight () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "weight");
  }

  auto
  CellRendererText::property_weight () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "weight");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Stretch>::value,
      "Type pango::Stretch cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_stretch () -> glib::PropertyProxy<pango::Stretch>
  {
    return glib::PropertyProxy<pango::Stretch> (this, "stretch");
  }

  auto
  CellRendererText::property_stretch () const -> glib::PropertyProxy_ReadOnly<pango::Stretch>
  {
    return glib::PropertyProxy_ReadOnly<pango::Stretch> (this, "stretch");
  }

  auto
  CellRendererText::property_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "size");
  }

  auto
  CellRendererText::property_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "size");
  }

  auto
  CellRendererText::property_size_points () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "size-points");
  }

  auto
  CellRendererText::property_size_points () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "size-points");
  }

  auto
  CellRendererText::property_scale () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "scale");
  }

  auto
  CellRendererText::property_scale () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "scale");
  }

  auto
  CellRendererText::property_editable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "editable");
  }

  auto
  CellRendererText::property_editable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "editable");
  }

  auto
  CellRendererText::property_strikethrough () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "strikethrough");
  }

  auto
  CellRendererText::property_strikethrough () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Underline>::value,
      "Type pango::Underline cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_underline () -> glib::PropertyProxy<pango::Underline>
  {
    return glib::PropertyProxy<pango::Underline> (this, "underline");
  }

  auto
  CellRendererText::property_underline () const -> glib::PropertyProxy_ReadOnly<pango::Underline>
  {
    return glib::PropertyProxy_ReadOnly<pango::Underline> (this, "underline");
  }

  auto
  CellRendererText::property_rise () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "rise");
  }

  auto
  CellRendererText::property_rise () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "rise");
  }

  auto
  CellRendererText::property_language () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "language");
  }

  auto
  CellRendererText::property_language () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "language");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::EllipsizeMode>::value,
      "Type pango::EllipsizeMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_ellipsize () -> glib::PropertyProxy<pango::EllipsizeMode>
  {
    return glib::PropertyProxy<pango::EllipsizeMode> (this, "ellipsize");
  }

  auto
  CellRendererText::property_ellipsize () const -> glib::PropertyProxy_ReadOnly<pango::EllipsizeMode>
  {
    return glib::PropertyProxy_ReadOnly<pango::EllipsizeMode> (this,
                                                               "ellipsize");
  }

  auto
  CellRendererText::property_width_chars () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "width-chars");
  }

  auto
  CellRendererText::property_width_chars () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width-chars");
  }

  auto
  CellRendererText::property_max_width_chars () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-width-chars");
  }

  auto
  CellRendererText::property_max_width_chars () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-width-chars");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::WrapMode>::value,
      "Type pango::WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_wrap_mode () -> glib::PropertyProxy<pango::WrapMode>
  {
    return glib::PropertyProxy<pango::WrapMode> (this, "wrap-mode");
  }

  auto
  CellRendererText::property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<pango::WrapMode>
  {
    return glib::PropertyProxy_ReadOnly<pango::WrapMode> (this, "wrap-mode");
  }

  auto
  CellRendererText::property_wrap_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "wrap-width");
  }

  auto
  CellRendererText::property_wrap_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "wrap-width");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Alignment>::value,
      "Type pango::Alignment cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererText::property_alignment () -> glib::PropertyProxy<pango::Alignment>
  {
    return glib::PropertyProxy<pango::Alignment> (this, "alignment");
  }

  auto
  CellRendererText::property_alignment () const -> glib::PropertyProxy_ReadOnly<pango::Alignment>
  {
    return glib::PropertyProxy_ReadOnly<pango::Alignment> (this, "alignment");
  }

  auto
  CellRendererText::property_background_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "background-set");
  }

  auto
  CellRendererText::property_background_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "background-set");
  }

  auto
  CellRendererText::property_foreground_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "foreground-set");
  }

  auto
  CellRendererText::property_foreground_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "foreground-set");
  }

  auto
  CellRendererText::property_family_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "family-set");
  }

  auto
  CellRendererText::property_family_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "family-set");
  }

  auto
  CellRendererText::property_style_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "style-set");
  }

  auto
  CellRendererText::property_style_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "style-set");
  }

  auto
  CellRendererText::property_variant_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "variant-set");
  }

  auto
  CellRendererText::property_variant_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "variant-set");
  }

  auto
  CellRendererText::property_weight_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "weight-set");
  }

  auto
  CellRendererText::property_weight_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "weight-set");
  }

  auto
  CellRendererText::property_stretch_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "stretch-set");
  }

  auto
  CellRendererText::property_stretch_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "stretch-set");
  }

  auto
  CellRendererText::property_size_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "size-set");
  }

  auto
  CellRendererText::property_size_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "size-set");
  }

  auto
  CellRendererText::property_scale_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "scale-set");
  }

  auto
  CellRendererText::property_scale_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "scale-set");
  }

  auto
  CellRendererText::property_editable_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "editable-set");
  }

  auto
  CellRendererText::property_editable_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "editable-set");
  }

  auto
  CellRendererText::property_strikethrough_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "strikethrough-set");
  }

  auto
  CellRendererText::property_strikethrough_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough-set");
  }

  auto
  CellRendererText::property_underline_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "underline-set");
  }

  auto
  CellRendererText::property_underline_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "underline-set");
  }

  auto
  CellRendererText::property_rise_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "rise-set");
  }

  auto
  CellRendererText::property_rise_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "rise-set");
  }

  auto
  CellRendererText::property_language_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "language-set");
  }

  auto
  CellRendererText::property_language_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "language-set");
  }

  auto
  CellRendererText::property_ellipsize_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "ellipsize-set");
  }

  auto
  CellRendererText::property_ellipsize_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "ellipsize-set");
  }

  auto
  CellRendererText::property_single_paragraph_mode () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "single-paragraph-mode");
  }

  auto
  CellRendererText::property_single_paragraph_mode () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "single-paragraph-mode");
  }

  auto
  CellRendererText::property_align_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "align-set");
  }

  auto
  CellRendererText::property_align_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "align-set");
  }

  auto
  CellRendererText::property_placeholder_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "placeholder-text");
  }

  auto
  CellRendererText::property_placeholder_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "placeholder-text");
  }

  auto
  gtk::CellRendererText::on_edited (const glib::ustring& path,
                                    const glib::ustring& new_text) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->edited)
      (*base->edited) (gobj (), path.c_str (), new_text.c_str ());
  }

} // namespace gtk

#endif

// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/label.hxx>
#include <libmm/gtk/label_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  Label::Label ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (label_class_.init ()))
  {
  }

  Label::Label (const glib::ustring& label, bool mnemonic)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (label_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
  }

  Label::Label (const glib::ustring& label,
                Align halign,
                Align valign,
                bool mnemonic)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (label_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
    set_halign (halign);
    set_valign (valign);
  }

  auto
  Label::select_region (int start_offset) -> void
  {
    gtk_label_select_region (gobj (), start_offset, -1);
  }

} // namespace gtk

namespace
{

  static auto
  Label_signal_activate_link_callback (GtkLabel* self,
                                       const gchar* p0,
                                       void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::ustring&)>;

    auto obj = dynamic_cast<Label*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Label_signal_activate_link_notify_callback (GtkLabel* self,
                                              const gchar* p0,
                                              void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<Label*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Label_signal_activate_link_info = {
      "activate-link",
      (GCallback) &Label_signal_activate_link_callback,
      (GCallback) &Label_signal_activate_link_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkLabel* object, bool take_copy) -> gtk::Label*
  {
    return dynamic_cast<gtk::Label*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Label_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Label_Class::class_init_function;

      register_derived_type (gtk_label_get_type ());
    }

    return *this;
  }

  auto
  Label_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Label_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Label ((GtkLabel*) (o)));
  }

  Label::Label (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Label::Label (GtkLabel* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Label::Label (Label&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Label::operator= (Label&& src) noexcept -> Label&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Label::~Label () noexcept
  {
    destroy_ ();
  }

  Label::CppClassType Label::label_class_;

  auto
  Label::get_type () -> GType
  {
    return label_class_.init ().get_type ();
  }

  auto
  Label::get_base_type () -> GType
  {
    return gtk_label_get_type ();
  }

  auto
  Label::set_text (const glib::ustring& str) -> void
  {
    gtk_label_set_text (gobj (), str.c_str ());
  }

  auto
  Label::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_label_get_text (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_attributes (pango::AttrList& attrs) -> void
  {
    gtk_label_set_attributes (gobj (), (attrs).gobj ());
  }

  auto
  Label::get_attributes () const -> pango::AttrList
  {
    return pango::AttrList (
        (gtk_label_get_attributes (const_cast<GtkLabel*> (gobj ()))));
  }

  auto
  Label::set_label (const glib::ustring& str) -> void
  {
    gtk_label_set_label (gobj (), str.c_str ());
  }

  auto
  Label::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_label_get_label (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_markup (const glib::ustring& str) -> void
  {
    gtk_label_set_markup (gobj (), str.c_str ());
  }

  auto
  Label::set_use_markup (bool setting) -> void
  {
    gtk_label_set_use_markup (gobj (), static_cast<int> (setting));
  }

  auto
  Label::get_use_markup () const -> bool
  {
    return gtk_label_get_use_markup (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_use_underline (bool setting) -> void
  {
    gtk_label_set_use_underline (gobj (), static_cast<int> (setting));
  }

  auto
  Label::get_use_underline () const -> bool
  {
    return gtk_label_get_use_underline (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_markup_with_mnemonic (const glib::ustring& str) -> void
  {
    gtk_label_set_markup_with_mnemonic (gobj (), str.c_str ());
  }

  auto
  Label::get_mnemonic_keyval () const -> guint
  {
    return gtk_label_get_mnemonic_keyval (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_mnemonic_widget (Widget& widget) -> void
  {
    gtk_label_set_mnemonic_widget (gobj (), (widget).gobj ());
  }

  auto
  Label::get_mnemonic_widget () -> Widget*
  {
    return glib::wrap (gtk_label_get_mnemonic_widget (gobj ()));
  }

  auto
  Label::get_mnemonic_widget () const -> const Widget*
  {
    return glib::wrap (
        gtk_label_get_mnemonic_widget (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_text_with_mnemonic (const glib::ustring& str) -> void
  {
    gtk_label_set_text_with_mnemonic (gobj (), str.c_str ());
  }

  auto
  Label::set_justify (Justification jtype) -> void
  {
    gtk_label_set_justify (gobj (), static_cast<GtkJustification> (jtype));
  }

  auto
  Label::get_justify () const -> Justification
  {
    return static_cast<Justification> (
        gtk_label_get_justify (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_ellipsize (pango::EllipsizeMode mode) -> void
  {
    gtk_label_set_ellipsize (gobj (), static_cast<PangoEllipsizeMode> (mode));
  }

  auto
  Label::get_ellipsize () const -> pango::EllipsizeMode
  {
    return static_cast<pango::EllipsizeMode> (
        gtk_label_get_ellipsize (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_width_chars (int n_chars) -> void
  {
    gtk_label_set_width_chars (gobj (), n_chars);
  }

  auto
  Label::get_width_chars () const -> int
  {
    return gtk_label_get_width_chars (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_max_width_chars (int n_chars) -> void
  {
    gtk_label_set_max_width_chars (gobj (), n_chars);
  }

  auto
  Label::get_max_width_chars () const -> int
  {
    return gtk_label_get_max_width_chars (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_lines (int lines) -> void
  {
    gtk_label_set_lines (gobj (), lines);
  }

  auto
  Label::get_lines () const -> int
  {
    return gtk_label_get_lines (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_wrap (bool wrap) -> void
  {
    gtk_label_set_wrap (gobj (), static_cast<int> (wrap));
  }

  auto
  Label::get_wrap () const -> bool
  {
    return gtk_label_get_wrap (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_wrap_mode (pango::WrapMode wrap_mode) -> void
  {
    gtk_label_set_wrap_mode (gobj (), static_cast<PangoWrapMode> (wrap_mode));
  }

  auto
  Label::get_wrap_mode () const -> pango::WrapMode
  {
    return static_cast<pango::WrapMode> (
        gtk_label_get_wrap_mode (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_natural_wrap_mode (NaturalWrapMode wrap_mode) -> void
  {
    gtk_label_set_natural_wrap_mode (
        gobj (),
        static_cast<GtkNaturalWrapMode> (wrap_mode));
  }

  auto
  Label::get_natural_wrap_mode () const -> NaturalWrapMode
  {
    return static_cast<NaturalWrapMode> (
        gtk_label_get_natural_wrap_mode (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_selectable (bool setting) -> void
  {
    gtk_label_set_selectable (gobj (), static_cast<int> (setting));
  }

  auto
  Label::get_selectable () const -> bool
  {
    return gtk_label_get_selectable (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::select_region (int start_offset, int end_offset) -> void
  {
    gtk_label_select_region (gobj (), start_offset, end_offset);
  }

  auto
  Label::get_selection_bounds (int& start, int& end) const -> bool
  {
    return gtk_label_get_selection_bounds (const_cast<GtkLabel*> (gobj ()),
                                           &(start),
                                           &(end));
  }

  auto
  Label::get_layout () -> glib::RefPtr<pango::Layout>
  {
    auto retvalue = glib::wrap (gtk_label_get_layout (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Label::get_layout () const -> glib::RefPtr<const pango::Layout>
  {
    return const_cast<Label*> (this)->get_layout ();
  }

  auto
  Label::get_layout_offsets (int& x, int& y) const -> void
  {
    gtk_label_get_layout_offsets (const_cast<GtkLabel*> (gobj ()), &(x), &(y));
  }

  auto
  Label::set_single_line_mode (bool single_line_mode) -> void
  {
    gtk_label_set_single_line_mode (gobj (),
                                    static_cast<int> (single_line_mode));
  }

  auto
  Label::get_single_line_mode () const -> bool
  {
    return gtk_label_get_single_line_mode (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::get_current_uri () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_label_get_current_uri (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_xalign (float xalign) -> void
  {
    gtk_label_set_xalign (gobj (), xalign);
  }

  auto
  Label::get_xalign () const -> float
  {
    return gtk_label_get_xalign (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_yalign (float yalign) -> void
  {
    gtk_label_set_yalign (gobj (), yalign);
  }

  auto
  Label::get_yalign () const -> float
  {
    return gtk_label_get_yalign (const_cast<GtkLabel*> (gobj ()));
  }

  auto
  Label::set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_label_set_extra_menu (gobj (), glib::unwrap (model));
  }

  auto
  Label::get_extra_menu () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_label_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Label::get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<Label*> (this)->get_extra_menu ();
  }

  auto
  Label::set_tabs (const pango::TabArray& tabs) -> void
  {
    gtk_label_set_tabs (gobj (), const_cast<pango::TabArray&> (tabs).gobj ());
  }

  auto
  Label::get_tabs () const -> pango::TabArray
  {
    return pango::TabArray (
        (gtk_label_get_tabs (const_cast<GtkLabel*> (gobj ()))),
        false);
  }

  auto
  Label::signal_activate_link () -> glib::SignalProxy<bool (const glib::ustring&)>
  {
    return glib::SignalProxy<bool (const glib::ustring&)> (
        this,
        &Label_signal_activate_link_info);
  }

  auto
  Label::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "label");
  }

  auto
  Label::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "label");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::AttrList>::value,
      "Type pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_attributes () -> glib::PropertyProxy<pango::AttrList>
  {
    return glib::PropertyProxy<pango::AttrList> (this, "attributes");
  }

  auto
  Label::property_attributes () const -> glib::PropertyProxy_ReadOnly<pango::AttrList>
  {
    return glib::PropertyProxy_ReadOnly<pango::AttrList> (this, "attributes");
  }

  auto
  Label::property_use_markup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-markup");
  }

  auto
  Label::property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-markup");
  }

  auto
  Label::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  Label::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
      "Type Justification cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_justify () -> glib::PropertyProxy<Justification>
  {
    return glib::PropertyProxy<Justification> (this, "justify");
  }

  auto
  Label::property_justify () const -> glib::PropertyProxy_ReadOnly<Justification>
  {
    return glib::PropertyProxy_ReadOnly<Justification> (this, "justify");
  }

  auto
  Label::property_wrap () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "wrap");
  }

  auto
  Label::property_wrap () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "wrap");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::WrapMode>::value,
      "Type pango::WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_wrap_mode () -> glib::PropertyProxy<pango::WrapMode>
  {
    return glib::PropertyProxy<pango::WrapMode> (this, "wrap-mode");
  }

  auto
  Label::property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<pango::WrapMode>
  {
    return glib::PropertyProxy_ReadOnly<pango::WrapMode> (this, "wrap-mode");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<NaturalWrapMode>::value,
      "Type NaturalWrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_natural_wrap_mode () -> glib::PropertyProxy<NaturalWrapMode>
  {
    return glib::PropertyProxy<NaturalWrapMode> (this, "natural-wrap-mode");
  }

  auto
  Label::property_natural_wrap_mode () const -> glib::PropertyProxy_ReadOnly<NaturalWrapMode>
  {
    return glib::PropertyProxy_ReadOnly<NaturalWrapMode> (this,
                                                          "natural-wrap-mode");
  }

  auto
  Label::property_selectable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "selectable");
  }

  auto
  Label::property_selectable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "selectable");
  }

  auto
  Label::property_mnemonic_keyval () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "mnemonic-keyval");
  }

  auto
  Label::property_mnemonic_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "mnemonic-widget");
  }

  auto
  Label::property_mnemonic_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "mnemonic-widget");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::EllipsizeMode>::value,
      "Type pango::EllipsizeMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_ellipsize () -> glib::PropertyProxy<pango::EllipsizeMode>
  {
    return glib::PropertyProxy<pango::EllipsizeMode> (this, "ellipsize");
  }

  auto
  Label::property_ellipsize () const -> glib::PropertyProxy_ReadOnly<pango::EllipsizeMode>
  {
    return glib::PropertyProxy_ReadOnly<pango::EllipsizeMode> (this,
                                                               "ellipsize");
  }

  auto
  Label::property_width_chars () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "width-chars");
  }

  auto
  Label::property_width_chars () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width-chars");
  }

  auto
  Label::property_single_line_mode () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "single-line-mode");
  }

  auto
  Label::property_single_line_mode () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "single-line-mode");
  }

  auto
  Label::property_max_width_chars () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-width-chars");
  }

  auto
  Label::property_max_width_chars () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-width-chars");
  }

  auto
  Label::property_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "lines");
  }

  auto
  Label::property_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "lines");
  }

  auto
  Label::property_xalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  Label::property_xalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  Label::property_yalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  Label::property_yalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  Label::property_extra_menu () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "extra-menu");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::TabArray>::value,
      "Type pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Label::property_tabs () -> glib::PropertyProxy<pango::TabArray>
  {
    return glib::PropertyProxy<pango::TabArray> (this, "tabs");
  }

  auto
  Label::property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>
  {
    return glib::PropertyProxy_ReadOnly<pango::TabArray> (this, "tabs");
  }

} // namespace gtk

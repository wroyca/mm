// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/label.hxx>
#include <libmm/gtk/label_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  Label::Label ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (label_class_.init ()))
  {
  }

  Label::Label (const Glib::ustring& label, bool mnemonic)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (label_class_.init (),
                                          "label",
                                          label.c_str (),
                                          "use_underline",
                                          gboolean (mnemonic),
                                          nullptr))
  {
  }

  Label::Label (const Glib::ustring& label,
                Align halign,
                Align valign,
                bool mnemonic)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (label_class_.init (),
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

} // namespace Gtk

namespace
{

  static auto
  Label_signal_activate_link_callback (GtkLabel* self,
                                       const gchar* p0,
                                       void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (const Glib::ustring&)>;

    auto obj = dynamic_cast<Label*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0)));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    auto obj = dynamic_cast<Label*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo Label_signal_activate_link_info = {
      "activate-link",
      (GCallback) &Label_signal_activate_link_callback,
      (GCallback) &Label_signal_activate_link_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkLabel* object, bool take_copy) -> Gtk::Label*
  {
    return dynamic_cast<Gtk::Label*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Label_Class::init () -> const Glib::Class&
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
  Label_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Label ((GtkLabel*) (o)));
  }

  Label::Label (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Label::Label (GtkLabel* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Label::Label (Label&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Label::operator= (Label&& src) noexcept -> Label&
  {
    Gtk::Widget::operator= (std::move (src));
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
  Label::set_text (const Glib::ustring& str) -> void
  {
    gtk_label_set_text (gobj (), str.c_str ());
  }

  auto
  Label::get_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_label_get_text (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_attributes (Pango::AttrList& attrs) -> void
  {
    gtk_label_set_attributes (gobj (), (attrs).gobj ());
  }

  auto
  Label::get_attributes () const -> Pango::AttrList
  {
    return Pango::AttrList (
        (gtk_label_get_attributes (const_cast<GtkLabel*> (gobj ()))));
  }

  auto
  Label::set_label (const Glib::ustring& str) -> void
  {
    gtk_label_set_label (gobj (), str.c_str ());
  }

  auto
  Label::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_label_get_label (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_markup (const Glib::ustring& str) -> void
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
  Label::set_markup_with_mnemonic (const Glib::ustring& str) -> void
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
    return Glib::wrap (gtk_label_get_mnemonic_widget (gobj ()));
  }

  auto
  Label::get_mnemonic_widget () const -> const Widget*
  {
    return Glib::wrap (
        gtk_label_get_mnemonic_widget (const_cast<GtkLabel*> (gobj ())));
  }

  auto
  Label::set_text_with_mnemonic (const Glib::ustring& str) -> void
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
  Label::set_ellipsize (Pango::EllipsizeMode mode) -> void
  {
    gtk_label_set_ellipsize (gobj (), static_cast<PangoEllipsizeMode> (mode));
  }

  auto
  Label::get_ellipsize () const -> Pango::EllipsizeMode
  {
    return static_cast<Pango::EllipsizeMode> (
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
  Label::set_wrap_mode (Pango::WrapMode wrap_mode) -> void
  {
    gtk_label_set_wrap_mode (gobj (), static_cast<PangoWrapMode> (wrap_mode));
  }

  auto
  Label::get_wrap_mode () const -> Pango::WrapMode
  {
    return static_cast<Pango::WrapMode> (
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
  Label::get_layout () -> Glib::RefPtr<Pango::Layout>
  {
    auto retvalue = Glib::wrap (gtk_label_get_layout (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Label::get_layout () const -> Glib::RefPtr<const Pango::Layout>
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
  Label::get_current_uri () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  Label::set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_label_set_extra_menu (gobj (), Glib::unwrap (model));
  }

  auto
  Label::get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_label_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Label::get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<Label*> (this)->get_extra_menu ();
  }

  auto
  Label::set_tabs (const Pango::TabArray& tabs) -> void
  {
    gtk_label_set_tabs (gobj (), const_cast<Pango::TabArray&> (tabs).gobj ());
  }

  auto
  Label::get_tabs () const -> Pango::TabArray
  {
    return Pango::TabArray (
        (gtk_label_get_tabs (const_cast<GtkLabel*> (gobj ()))),
        false);
  }

  auto
  Label::signal_activate_link () -> Glib::SignalProxy<bool (const Glib::ustring&)>
  {
    return Glib::SignalProxy<bool (const Glib::ustring&)> (
        this,
        &Label_signal_activate_link_info);
  }

  auto
  Label::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "label");
  }

  auto
  Label::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "label");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
      "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_attributes () -> Glib::PropertyProxy<Pango::AttrList>
  {
    return Glib::PropertyProxy<Pango::AttrList> (this, "attributes");
  }

  auto
  Label::property_attributes () const -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::AttrList> (this, "attributes");
  }

  auto
  Label::property_use_markup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-markup");
  }

  auto
  Label::property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-markup");
  }

  auto
  Label::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  Label::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
      "Type Justification cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_justify () -> Glib::PropertyProxy<Justification>
  {
    return Glib::PropertyProxy<Justification> (this, "justify");
  }

  auto
  Label::property_justify () const -> Glib::PropertyProxy_ReadOnly<Justification>
  {
    return Glib::PropertyProxy_ReadOnly<Justification> (this, "justify");
  }

  auto
  Label::property_wrap () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "wrap");
  }

  auto
  Label::property_wrap () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "wrap");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::WrapMode>::value,
      "Type Pango::WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_wrap_mode () -> Glib::PropertyProxy<Pango::WrapMode>
  {
    return Glib::PropertyProxy<Pango::WrapMode> (this, "wrap-mode");
  }

  auto
  Label::property_wrap_mode () const -> Glib::PropertyProxy_ReadOnly<Pango::WrapMode>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::WrapMode> (this, "wrap-mode");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<NaturalWrapMode>::value,
      "Type NaturalWrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_natural_wrap_mode () -> Glib::PropertyProxy<NaturalWrapMode>
  {
    return Glib::PropertyProxy<NaturalWrapMode> (this, "natural-wrap-mode");
  }

  auto
  Label::property_natural_wrap_mode () const -> Glib::PropertyProxy_ReadOnly<NaturalWrapMode>
  {
    return Glib::PropertyProxy_ReadOnly<NaturalWrapMode> (this,
                                                          "natural-wrap-mode");
  }

  auto
  Label::property_selectable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "selectable");
  }

  auto
  Label::property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "selectable");
  }

  auto
  Label::property_mnemonic_keyval () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "mnemonic-keyval");
  }

  auto
  Label::property_mnemonic_widget () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "mnemonic-widget");
  }

  auto
  Label::property_mnemonic_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "mnemonic-widget");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Pango::EllipsizeMode>::value,
      "Type Pango::EllipsizeMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_ellipsize () -> Glib::PropertyProxy<Pango::EllipsizeMode>
  {
    return Glib::PropertyProxy<Pango::EllipsizeMode> (this, "ellipsize");
  }

  auto
  Label::property_ellipsize () const -> Glib::PropertyProxy_ReadOnly<Pango::EllipsizeMode>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::EllipsizeMode> (this,
                                                               "ellipsize");
  }

  auto
  Label::property_width_chars () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "width-chars");
  }

  auto
  Label::property_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "width-chars");
  }

  auto
  Label::property_single_line_mode () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "single-line-mode");
  }

  auto
  Label::property_single_line_mode () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "single-line-mode");
  }

  auto
  Label::property_max_width_chars () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "max-width-chars");
  }

  auto
  Label::property_max_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "max-width-chars");
  }

  auto
  Label::property_lines () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "lines");
  }

  auto
  Label::property_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "lines");
  }

  auto
  Label::property_xalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  Label::property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  Label::property_yalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  Label::property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  Label::property_extra_menu () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "extra-menu");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
      "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Label::property_tabs () -> Glib::PropertyProxy<Pango::TabArray>
  {
    return Glib::PropertyProxy<Pango::TabArray> (this, "tabs");
  }

  auto
  Label::property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::TabArray> (this, "tabs");
  }

} // namespace Gtk

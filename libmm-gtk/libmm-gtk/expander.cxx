

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/expander.hxx>
#include <libmm-gtk/expander_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  Expander::Expander (const Glib::ustring& label, const bool mnemonic)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (expander_class_.init (),
                                     "label",
                                     label.c_str (),
                                     "use_underline",
                                     gboolean (mnemonic),
                                     nullptr))
  {
  }

  auto
  Expander::unset_child () -> void
  {
    gtk_expander_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkExpander* object, const bool take_copy) -> Gtk::Expander*
  {
    return dynamic_cast<Gtk::Expander*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Expander_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Expander_Class::class_init_function;

      register_derived_type (gtk_expander_get_type ());
    }

    return *this;
  }

  auto
  Expander_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Expander_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Expander ((GtkExpander*) o));
  }

  Expander::Expander (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Expander::Expander (GtkExpander* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Expander::Expander (Expander&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  Expander::operator= (Expander&& src) noexcept -> Expander&
  {
    Widget::operator= (std::move (src));
    return *this;
  }

  Expander::~Expander () noexcept
  {
    destroy_ ();
  }

  Expander::CppClassType Expander::expander_class_;

  auto
  Expander::get_type () -> GType
  {
    return expander_class_.init ().get_type ();
  }

  auto
  Expander::get_base_type () -> GType
  {
    return gtk_expander_get_type ();
  }

  Expander::Expander ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (expander_class_.init ()))
  {
  }

  auto
  Expander::set_expanded (const bool expanded) -> void
  {
    gtk_expander_set_expanded (gobj (), expanded);
  }

  auto
  Expander::get_expanded () const -> bool
  {
    return gtk_expander_get_expanded (const_cast<GtkExpander*> (gobj ()));
  }

  auto
  Expander::set_label (const Glib::ustring& label) -> void
  {
    gtk_expander_set_label (gobj (), label.c_str ());
  }

  auto
  Expander::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_expander_get_label (const_cast<GtkExpander*> (gobj ())));
  }

  auto
  Expander::set_use_underline (const bool use_underline) -> void
  {
    gtk_expander_set_use_underline (gobj (), use_underline);
  }

  auto
  Expander::get_use_underline () const -> bool
  {
    return gtk_expander_get_use_underline (const_cast<GtkExpander*> (gobj ()));
  }

  auto
  Expander::set_use_markup (const bool use_markup) -> void
  {
    gtk_expander_set_use_markup (gobj (), use_markup);
  }

  auto
  Expander::get_use_markup () const -> bool
  {
    return gtk_expander_get_use_markup (const_cast<GtkExpander*> (gobj ()));
  }

  auto
  Expander::set_label_widget (Widget& label_widget) -> void
  {
    gtk_expander_set_label_widget (gobj (), label_widget.gobj ());
  }

  auto
  Expander::get_label_widget () -> Widget*
  {
    return Glib::wrap (gtk_expander_get_label_widget (gobj ()));
  }

  auto
  Expander::get_label_widget () const -> const Widget*
  {
    return const_cast<Expander*> (this)->get_label_widget ();
  }

  auto
  Expander::set_resize_toplevel (const bool resize_toplevel) -> void
  {
    gtk_expander_set_resize_toplevel (gobj (), resize_toplevel);
  }

  auto
  Expander::get_resize_toplevel () const -> bool
  {
    return gtk_expander_get_resize_toplevel (
        const_cast<GtkExpander*> (gobj ()));
  }

  auto
  Expander::set_child (Widget& child) -> void
  {
    gtk_expander_set_child (gobj (), child.gobj ());
  }

  auto
  Expander::get_child () -> Widget*
  {
    return Glib::wrap (gtk_expander_get_child (gobj ()));
  }

  auto
  Expander::get_child () const -> const Widget*
  {
    return const_cast<Expander*> (this)->get_child ();
  }

  auto
  Expander::property_expanded () -> Glib::PropertyProxy<bool>
  {
    return {this, "expanded"};
  }

  auto
  Expander::property_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "expanded"};
  }

  auto
  Expander::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "label"};
  }

  auto
  Expander::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "label"};
  }

  auto
  Expander::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  Expander::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

  auto
  Expander::property_use_markup () -> Glib::PropertyProxy<bool>
  {
    return {this, "use-markup"};
  }

  auto
  Expander::property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-markup"};
  }

  auto
  Expander::property_label_widget () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "label-widget"};
  }

  auto
  Expander::property_label_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "label-widget"};
  }

  auto
  Expander::property_resize_toplevel () -> Glib::PropertyProxy<bool>
  {
    return {this, "resize-toplevel"};
  }

  auto
  Expander::property_resize_toplevel () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "resize-toplevel"};
  }

  auto
  Expander::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  Expander::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk

// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/dialog_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace Gtk
{

  Dialog::Dialog (const Glib::ustring& title,
                  Gtk::Window& parent,
                  bool modal,
                  bool use_header_bar)
    : Glib::ObjectBase (nullptr),
      Gtk::Window (Glib::ConstructParams (dialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          "use-header-bar",
                                          static_cast<int> (use_header_bar),
                                          nullptr))
  {
    set_modal (modal);
    set_transient_for (parent);
  }

  Dialog::Dialog (const Glib::ustring& title, bool modal, bool use_header_bar)
    : Glib::ObjectBase (nullptr),
      Gtk::Window (Glib::ConstructParams (dialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          "use-header-bar",
                                          static_cast<int> (use_header_bar),
                                          nullptr))
  {
    set_modal (modal);
  }

} // namespace Gtk

namespace
{

  static auto
  Dialog_signal_response_callback (GtkDialog* self, gint p0, void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (int)>;

    auto obj = dynamic_cast<Dialog*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Dialog_signal_response_info = {
      "response",
      (GCallback) &Dialog_signal_response_callback,
      (GCallback) &Dialog_signal_response_callback};

} // namespace

auto
Glib::Value<Gtk::ResponseType>::value_type () -> GType
{
  return gtk_response_type_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkDialog* object, bool take_copy) -> Gtk::Dialog*
  {
    return dynamic_cast<Gtk::Dialog*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Dialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Dialog_Class::class_init_function;

      register_derived_type (gtk_dialog_get_type ());
    }

    return *this;
  }

  auto
  Dialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->response = &response_callback;
  }

  auto
  Dialog_Class::response_callback (GtkDialog* self, gint p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_response (p0);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->response)
      (*base->response) (self, p0);
  }

  auto
  Dialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new Dialog ((GtkDialog*) (o));
  }

  Dialog::Dialog (const Glib::ConstructParams& construct_params)
    : Gtk::Window (construct_params)
  {
  }

  Dialog::Dialog (GtkDialog* castitem)
    : Gtk::Window ((GtkWindow*) (castitem))
  {
  }

  Dialog::Dialog (Dialog&& src) noexcept
    : Gtk::Window (std::move (src))
  {
  }

  auto
  Dialog::operator= (Dialog&& src) noexcept -> Dialog&
  {
    Gtk::Window::operator= (std::move (src));
    return *this;
  }

  Dialog::~Dialog () noexcept
  {
    destroy_ ();
  }

  Dialog::CppClassType Dialog::dialog_class_;

  auto
  Dialog::get_type () -> GType
  {
    return dialog_class_.init ().get_type ();
  }

  auto
  Dialog::get_base_type () -> GType
  {
    return gtk_dialog_get_type ();
  }

  Dialog::Dialog ()
    : Glib::ObjectBase (nullptr),
      Gtk::Window (Glib::ConstructParams (dialog_class_.init ()))
  {
  }

  auto
  Dialog::add_action_widget (Widget& child, int response_id) -> void
  {
    gtk_dialog_add_action_widget (gobj (), (child).gobj (), response_id);
  }

  auto
  Dialog::add_button (const Glib::ustring& button_text, int response_id) -> Button*
  {
    return Glib::wrap (
        (GtkButton*) (gtk_dialog_add_button (gobj (),
                                             button_text.c_str (),
                                             response_id)));
  }

  auto
  Dialog::set_response_sensitive (int response_id, bool setting) -> void
  {
    gtk_dialog_set_response_sensitive (gobj (),
                                       response_id,
                                       static_cast<int> (setting));
  }

  auto
  Dialog::set_default_response (int response_id) -> void
  {
    gtk_dialog_set_default_response (gobj (), response_id);
  }

  auto
  Dialog::get_widget_for_response (int response_id) -> Widget*
  {
    return Glib::wrap (
        gtk_dialog_get_widget_for_response (gobj (), response_id));
  }

  auto
  Dialog::get_widget_for_response (int response_id) const -> const Widget*
  {
    return const_cast<Dialog*> (this)->get_widget_for_response (response_id);
  }

  auto
  Dialog::get_response_for_widget (const Gtk::Widget& widget) const -> int
  {
    return gtk_dialog_get_response_for_widget (
        const_cast<GtkDialog*> (gobj ()),
        const_cast<GtkWidget*> (widget.gobj ()));
  }

  auto
  Dialog::response (int response_id) -> void
  {
    gtk_dialog_response (gobj (), response_id);
  }

  auto
  Dialog::get_content_area () -> Box*
  {
    return Glib::wrap ((GtkBox*) (gtk_dialog_get_content_area (gobj ())));
  }

  auto
  Dialog::get_content_area () const -> const Box*
  {
    return const_cast<Dialog*> (this)->get_content_area ();
  }

  auto
  Dialog::get_header_bar () -> HeaderBar*
  {
    return Glib::wrap ((GtkHeaderBar*) (gtk_dialog_get_header_bar (gobj ())));
  }

  auto
  Dialog::get_header_bar () const -> const HeaderBar*
  {
    return const_cast<Dialog*> (this)->get_header_bar ();
  }

  auto
  Dialog::signal_response () -> Glib::SignalProxy<void (int)>
  {
    return Glib::SignalProxy<void (int)> (this, &Dialog_signal_response_info);
  }

  auto
  Dialog::property_use_header_bar () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-header-bar");
  }

  auto
  Gtk::Dialog::on_response (int response_id) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
      (*base->response) (gobj (), response_id);
  }

} // namespace Gtk

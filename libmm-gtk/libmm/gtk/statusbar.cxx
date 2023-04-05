// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/statusbar.hxx>
  #include <libmm/gtk/statusbar_p.hxx>

  #include <gtk/gtk.h>

namespace
{

  static auto
  Statusbar_signal_text_pushed_callback (GtkStatusbar* self,
                                         guint p0,
                                         const gchar* p1,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint, const glib::ustring&)>;

    auto obj = dynamic_cast<Statusbar*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, glib::convert_const_gchar_ptr_to_ustring (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Statusbar_signal_text_pushed_info = {
      "text_pushed",
      (GCallback) &Statusbar_signal_text_pushed_callback,
      (GCallback) &Statusbar_signal_text_pushed_callback};

  static auto
  Statusbar_signal_text_popped_callback (GtkStatusbar* self,
                                         guint p0,
                                         const gchar* p1,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint, const glib::ustring&)>;

    auto obj = dynamic_cast<Statusbar*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (p0, glib::convert_const_gchar_ptr_to_ustring (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Statusbar_signal_text_popped_info = {
      "text_popped",
      (GCallback) &Statusbar_signal_text_popped_callback,
      (GCallback) &Statusbar_signal_text_popped_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkStatusbar* object, bool take_copy) -> gtk::Statusbar*
  {
    return dynamic_cast<gtk::Statusbar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Statusbar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Statusbar_Class::class_init_function;

      register_derived_type (gtk_statusbar_get_type ());
    }

    return *this;
  }

  auto
  Statusbar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Statusbar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Statusbar ((GtkStatusbar*) (o)));
  }

  Statusbar::Statusbar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Statusbar::Statusbar (GtkStatusbar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Statusbar::Statusbar (Statusbar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Statusbar::operator= (Statusbar&& src) noexcept -> Statusbar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Statusbar::~Statusbar () noexcept
  {
    destroy_ ();
  }

  Statusbar::CppClassType Statusbar::statusbar_class_;

  auto
  Statusbar::get_type () -> GType
  {
    return statusbar_class_.init ().get_type ();
  }

  auto
  Statusbar::get_base_type () -> GType
  {
    return gtk_statusbar_get_type ();
  }

  Statusbar::Statusbar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (statusbar_class_.init ()))
  {
  }

  auto
  Statusbar::get_context_id (const glib::ustring& context_description) -> guint
  {
    return gtk_statusbar_get_context_id (gobj (), context_description.c_str ());
  }

  auto
  Statusbar::push (const glib::ustring& text, guint context_id) -> guint
  {
    return gtk_statusbar_push (gobj (), context_id, text.c_str ());
  }

  auto
  Statusbar::pop (guint context_id) -> void
  {
    gtk_statusbar_pop (gobj (), context_id);
  }

  auto
  Statusbar::remove_message (guint message_id, guint context_id) -> void
  {
    gtk_statusbar_remove (gobj (), context_id, message_id);
  }

  auto
  Statusbar::remove_all_messages (guint context_id) -> void
  {
    gtk_statusbar_remove_all (gobj (), context_id);
  }

  auto
  Statusbar::signal_text_pushed () -> glib::SignalProxy<void (guint, const glib::ustring&)>
  {
    return glib::SignalProxy<void (guint, const glib::ustring&)> (
        this,
        &Statusbar_signal_text_pushed_info);
  }

  auto
  Statusbar::signal_text_popped () -> glib::SignalProxy<void (guint, const glib::ustring&)>
  {
    return glib::SignalProxy<void (guint, const glib::ustring&)> (
        this,
        &Statusbar_signal_text_popped_info);
  }

} // namespace gtk

#endif

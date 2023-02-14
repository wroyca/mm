

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/linkbutton.hxx>
#include <libmm-gtk/linkbutton_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  LinkButton_signal_activate_link_callback (GtkLinkButton* self, void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool ()>;

    const auto obj = dynamic_cast<LinkButton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  LinkButton_signal_activate_link_notify_callback (GtkLinkButton* self,
                                                   void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void ()>;

    const auto obj = dynamic_cast<LinkButton*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo LinkButton_signal_activate_link_info = {
      "activate-link",
      (GCallback) &LinkButton_signal_activate_link_callback,
      (GCallback) &LinkButton_signal_activate_link_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkLinkButton* object, const bool take_copy) -> Gtk::LinkButton*
  {
    return dynamic_cast<Gtk::LinkButton*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  LinkButton_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LinkButton_Class::class_init_function;

      register_derived_type (gtk_link_button_get_type ());
    }

    return *this;
  }

  auto
  LinkButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  LinkButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new LinkButton ((GtkLinkButton*) o));
  }

  LinkButton::LinkButton (const Glib::ConstructParams& construct_params)
    : Button (construct_params)
  {
  }

  LinkButton::LinkButton (GtkLinkButton* castitem)
    : Button ((GtkButton*) castitem)
  {
  }

  LinkButton::LinkButton (LinkButton&& src) noexcept
    : Button (std::move (src))
  {
  }

  auto
  LinkButton::operator= (LinkButton&& src) noexcept -> LinkButton&
  {
    Button::operator= (std::move (src));
    return *this;
  }

  LinkButton::~LinkButton () noexcept
  {
    destroy_ ();
  }

  LinkButton::CppClassType LinkButton::linkbutton_class_;

  auto
  LinkButton::get_type () -> GType
  {
    return linkbutton_class_.init ().get_type ();
  }

  auto
  LinkButton::get_base_type () -> GType
  {
    return gtk_link_button_get_type ();
  }

  LinkButton::LinkButton ()
    : ObjectBase (nullptr),
      Button (Glib::ConstructParams (linkbutton_class_.init ()))
  {
  }

  LinkButton::LinkButton (const Glib::ustring& uri, const Glib::ustring& label)
    : ObjectBase (nullptr),
      Button (Glib::ConstructParams (linkbutton_class_.init (),
                                     "uri",
                                     uri.c_str (),
                                     "label",
                                     label.c_str (),
                                     nullptr))
  {
  }

  auto
  LinkButton::get_uri () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_link_button_get_uri (const_cast<GtkLinkButton*> (gobj ())));
  }

  auto
  LinkButton::set_uri (const Glib::ustring& uri) -> void
  {
    gtk_link_button_set_uri (gobj (), uri.c_str ());
  }

  auto
  LinkButton::get_visited () const -> bool
  {
    return gtk_link_button_get_visited (const_cast<GtkLinkButton*> (gobj ()));
  }

  auto
  LinkButton::set_visited (const bool visited) -> void
  {
    gtk_link_button_set_visited (gobj (), visited);
  }

  auto
  LinkButton::signal_activate_link () -> Glib::SignalProxy<bool ()>
  {
    return {this, &LinkButton_signal_activate_link_info};
  }

  auto
  LinkButton::property_uri () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "uri"};
  }

  auto
  LinkButton::property_uri () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "uri"};
  }

  auto
  LinkButton::property_visited () -> Glib::PropertyProxy<bool>
  {
    return {this, "visited"};
  }

  auto
  LinkButton::property_visited () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "visited"};
  }

} // namespace Gtk

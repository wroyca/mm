


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/aboutdialog.hxx>
#include <libmm-gtk/aboutdialog_p.hxx>


/*
 * Copyright 2004 The gtkmm Development Team
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

#include <libmm-glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

// use-header-bar is construct-only. It must be set in the constructor,
// if you don't want the default value.
AboutDialog::AboutDialog (const bool use_header_bar)
  :
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  ObjectBase(nullptr),
  Window(
    Glib::ConstructParams (
      aboutdialog_class_.init(), "use-header-bar", use_header_bar, nullptr))
{
}

auto AboutDialog::set_logo_default () -> void
{
  gtk_about_dialog_set_logo(gobj(), nullptr);
}

} // namespace Gtk


namespace
{


auto AboutDialog_signal_activate_link_callback(GtkAboutDialog* self, const gchar* p0,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const std::string&)>;

  const auto obj = dynamic_cast<AboutDialog*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_stdstring(p0)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto AboutDialog_signal_activate_link_notify_callback(GtkAboutDialog* self, const gchar* p0, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const std::string&)>;

  const auto obj = dynamic_cast<AboutDialog*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_stdstring(p0)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo AboutDialog_signal_activate_link_info =
{
  "activate-link",
  (GCallback) &AboutDialog_signal_activate_link_callback,
  (GCallback) &AboutDialog_signal_activate_link_notify_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::License>::value_type() -> GType
{
  return gtk_license_get_type();
}


namespace Glib
{

auto wrap(GtkAboutDialog* object, const bool take_copy) -> Gtk::AboutDialog*
{
  return dynamic_cast<Gtk::AboutDialog *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto AboutDialog_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AboutDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_about_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto AboutDialog_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AboutDialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new AboutDialog((GtkAboutDialog*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

AboutDialog::AboutDialog(const Glib::ConstructParams& construct_params)
: Window(construct_params)
{
  }

AboutDialog::AboutDialog(GtkAboutDialog* castitem)
: Window((GtkWindow*)castitem)
{
  }


AboutDialog::AboutDialog(AboutDialog&& src) noexcept
: Window(std::move(src))
{}

auto AboutDialog::operator=(AboutDialog&& src) noexcept -> AboutDialog&
{
  Window::operator=(std::move(src));
  return *this;
}

AboutDialog::~AboutDialog() noexcept
{
  destroy_();
}

AboutDialog::CppClassType AboutDialog::aboutdialog_class_; // initialize static member

auto AboutDialog::get_type() -> GType
{
  return aboutdialog_class_.init().get_type();
}


auto AboutDialog::get_base_type() -> GType
{
  return gtk_about_dialog_get_type();
}


AboutDialog::AboutDialog()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(aboutdialog_class_.init()))
{


}

auto AboutDialog::get_program_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_program_name(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_program_name (const Glib::ustring &name) -> void
{
  gtk_about_dialog_set_program_name(gobj(), name.c_str());
}

auto AboutDialog::get_version() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_version(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_version (const Glib::ustring &version) -> void
{
  gtk_about_dialog_set_version(gobj(), version.c_str());
}

auto AboutDialog::get_copyright() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_copyright(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_copyright (const Glib::ustring &copyright) -> void
{
  gtk_about_dialog_set_copyright(gobj(), copyright.c_str());
}

auto AboutDialog::get_comments() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_comments(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_comments (const Glib::ustring &comments) -> void
{
  gtk_about_dialog_set_comments(gobj(), comments.c_str());
}

auto AboutDialog::get_license() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_license(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_license (const Glib::ustring &license) -> void
{
  gtk_about_dialog_set_license(gobj(), license.empty() ? nullptr : license.c_str());
}

auto AboutDialog::get_license_type() const -> License
{
  return static_cast<License>(gtk_about_dialog_get_license_type(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_license_type (License license_type) -> void
{
  gtk_about_dialog_set_license_type(gobj(), static_cast<GtkLicense>(license_type));
}

auto AboutDialog::get_system_information() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_system_information(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_system_information (const Glib::ustring &system_information) -> void
{
  gtk_about_dialog_set_system_information(gobj(), system_information.empty() ? nullptr : system_information.c_str());
}

auto AboutDialog::get_website() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_website(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_website (const Glib::ustring &website) -> void
{
  gtk_about_dialog_set_website(gobj(), website.c_str());
}

auto AboutDialog::get_website_label() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_website_label(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_website_label (const Glib::ustring &website_label) -> void
{
  gtk_about_dialog_set_website_label(gobj(), website_label.c_str());
}

auto AboutDialog::get_authors() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gtk_about_dialog_get_authors(const_cast<GtkAboutDialog*>(gobj())), Glib::OWNERSHIP_NONE);
}

auto AboutDialog::set_authors (const std::vector <Glib::ustring> &authors) const -> void
{
  gtk_about_dialog_set_authors(const_cast<GtkAboutDialog*>(gobj()), Glib::ArrayHandler<Glib::ustring>::vector_to_array(authors).data ());
}

auto AboutDialog::get_documenters() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gtk_about_dialog_get_documenters(const_cast<GtkAboutDialog*>(gobj())), Glib::OWNERSHIP_NONE);
}

auto AboutDialog::set_documenters (const std::vector <Glib::ustring> &documenters) -> void
{
  gtk_about_dialog_set_documenters(gobj(), Glib::ArrayHandler<Glib::ustring>::vector_to_array(documenters).data ());
}

auto AboutDialog::get_artists() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gtk_about_dialog_get_artists(const_cast<GtkAboutDialog*>(gobj())), Glib::OWNERSHIP_NONE);
}

auto AboutDialog::set_artists (const std::vector <Glib::ustring> &artists) -> void
{
  gtk_about_dialog_set_artists(gobj(), Glib::ArrayHandler<Glib::ustring>::vector_to_array(artists).data ());
}

auto AboutDialog::get_translator_credits() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_translator_credits(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_translator_credits (const Glib::ustring &translator_credits) -> void
{
  gtk_about_dialog_set_translator_credits(gobj(), translator_credits.c_str());
}

auto AboutDialog::get_logo() -> Glib::RefPtr<Gdk::Paintable>
{
  auto retvalue = Glib::wrap(gtk_about_dialog_get_logo(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto AboutDialog::get_logo() const -> Glib::RefPtr<const Gdk::Paintable>
{
  return const_cast<AboutDialog*>(this)->get_logo();
}

auto AboutDialog::set_logo (const Glib::RefPtr <const Gdk::Paintable> &logo) -> void
{
  gtk_about_dialog_set_logo(gobj(), const_cast<GdkPaintable*>(Glib::unwrap(logo)));
}

auto AboutDialog::get_logo_icon_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_about_dialog_get_logo_icon_name(const_cast<GtkAboutDialog*>(gobj())));
}

auto AboutDialog::set_logo_icon_name (const Glib::ustring &icon_name) -> void
{
  gtk_about_dialog_set_logo_icon_name(gobj(), icon_name.c_str());
}

auto AboutDialog::get_wrap_license() const -> bool
{
  return gtk_about_dialog_get_wrap_license(const_cast<GtkAboutDialog*>(gobj()));
}

auto AboutDialog::set_wrap_license (
  const bool wrap_license) -> void
{
  gtk_about_dialog_set_wrap_license(gobj(), wrap_license);
}

auto AboutDialog::add_credit_section (
  const Glib::ustring &section_name, const std::vector <Glib::ustring> &people) -> void
{
  gtk_about_dialog_add_credit_section(gobj(), section_name.c_str(), Glib::ArrayHandler<Glib::ustring>::vector_to_array(people).data ());
}


auto AboutDialog::signal_activate_link() -> Glib::SignalProxy<bool(const std::string&)>
{
  return {this, &AboutDialog_signal_activate_link_info};
}


auto AboutDialog::property_program_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "program-name"};
}

auto AboutDialog::property_program_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "program-name"};
}

auto AboutDialog::property_version() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "version"};
}

auto AboutDialog::property_version() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "version"};
}

auto AboutDialog::property_copyright() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "copyright"};
}

auto AboutDialog::property_copyright() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "copyright"};
}

auto AboutDialog::property_comments() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "comments"};
}

auto AboutDialog::property_comments() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "comments"};
}

auto AboutDialog::property_website() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "website"};
}

auto AboutDialog::property_website() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "website"};
}

auto AboutDialog::property_website_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "website-label"};
}

auto AboutDialog::property_website_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "website-label"};
}

auto AboutDialog::property_license() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "license"};
}

auto AboutDialog::property_license() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "license"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<License>::value,
  "Type License cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AboutDialog::property_license_type() -> Glib::PropertyProxy< License >
{
  return {this, "license-type"};
}

auto AboutDialog::property_license_type() const -> Glib::PropertyProxy_ReadOnly< License >
{
  return {this, "license-type"};
}

auto AboutDialog::property_system_information() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "system-information"};
}

auto AboutDialog::property_system_information() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "system-information"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<std::vector<Glib::ustring>>::value,
  "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AboutDialog::property_authors() -> Glib::PropertyProxy< std::vector<Glib::ustring> >
{
  return {this, "authors"};
}

auto AboutDialog::property_authors() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >
{
  return {this, "authors"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<std::vector<Glib::ustring>>::value,
  "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AboutDialog::property_documenters() -> Glib::PropertyProxy< std::vector<Glib::ustring> >
{
  return {this, "documenters"};
}

auto AboutDialog::property_documenters() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >
{
  return {this, "documenters"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<std::vector<Glib::ustring>>::value,
  "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AboutDialog::property_translator_credits() -> Glib::PropertyProxy< std::vector<Glib::ustring> >
{
  return {this, "translator-credits"};
}

auto AboutDialog::property_translator_credits() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >
{
  return {this, "translator-credits"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<std::vector<Glib::ustring>>::value,
  "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AboutDialog::property_artists() -> Glib::PropertyProxy< std::vector<Glib::ustring> >
{
  return {this, "artists"};
}

auto AboutDialog::property_artists() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >
{
  return {this, "artists"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Paintable>>::value,
  "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AboutDialog::property_logo() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "logo"};
}

auto AboutDialog::property_logo() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "logo"};
}

auto AboutDialog::property_logo_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "logo-icon-name"};
}

auto AboutDialog::property_logo_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "logo-icon-name"};
}

auto AboutDialog::property_wrap_license() -> Glib::PropertyProxy< bool >
{
  return {this, "wrap-license"};
}

auto AboutDialog::property_wrap_license() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "wrap-license"};
}


} // namespace Gtk


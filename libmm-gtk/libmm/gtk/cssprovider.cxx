// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/cssprovider.hxx>
#include <libmm/gtk/cssprovider_p.hxx>

#include <gtk/gtk.h>

namespace
{
  static auto
  CssProvider_signal_parsing_error_callback (GtkCssProvider* self,
                                             GtkCssSection* p0,
                                             const GError* p1,
                                             void* data) -> void
  {
    using namespace Gtk;
    typedef sigc::slot<void (const Glib::RefPtr<const CssSection>&,
                             const Glib::Error&)>
        SlotType;

    auto obj = dynamic_cast<CssProvider*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        Glib::Error::throw_exception (g_error_copy (p1));
      }
      catch (const Glib::Error& ex)
      {
        try
        {
          if (sigc::slot_base* const slot =
                  Glib::SignalProxyNormal::data_to_slot (data))
            (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true), ex);
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }
  }

} // namespace

namespace Gtk
{

  auto
  CssProvider::load_from_data (const std::string& data) -> void
  {
    gtk_css_provider_load_from_data (gobj (), data.c_str (), -1);
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo CssProvider_signal_parsing_error_info = {
      "parsing-error",
      (GCallback) &CssProvider_signal_parsing_error_callback,
      (GCallback) &CssProvider_signal_parsing_error_callback};

}

Gtk::CssParserError::CssParserError (Gtk::CssParserError::Code error_code,
                                     const Glib::ustring& error_message)
  : Glib::Error (GTK_CSS_PARSER_ERROR, error_code, error_message)
{
}

Gtk::CssParserError::CssParserError (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gtk::CssParserError::code () const -> Gtk::CssParserError::Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gtk::CssParserError::throw_func (GError* gobject) -> void
{
  throw Gtk::CssParserError (gobject);
}

auto
Glib::Value<Gtk::CssParserError::Code>::value_type () -> GType
{
  return gtk_css_parser_error_get_type ();
}

Gtk::CssParserWarning::CssParserWarning (Gtk::CssParserWarning::Code error_code,
                                         const Glib::ustring& error_message)
  : Glib::Error (GTK_CSS_PARSER_WARNING, error_code, error_message)
{
}

Gtk::CssParserWarning::CssParserWarning (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gtk::CssParserWarning::code () const -> Gtk::CssParserWarning::Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gtk::CssParserWarning::throw_func (GError* gobject) -> void
{
  throw Gtk::CssParserWarning (gobject);
}

auto
Glib::Value<Gtk::CssParserWarning::Code>::value_type () -> GType
{
  return gtk_css_parser_warning_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkCssProvider* object, bool take_copy) -> Glib::RefPtr<Gtk::CssProvider>
  {
    return Glib::make_refptr_for_instance<Gtk::CssProvider> (
        dynamic_cast<Gtk::CssProvider*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CssProvider_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CssProvider_Class::class_init_function;

      register_derived_type (gtk_css_provider_get_type ());

      StyleProvider::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CssProvider_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CssProvider_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CssProvider ((GtkCssProvider*) object);
  }

  auto
  CssProvider::gobj_copy () -> GtkCssProvider*
  {
    reference ();
    return gobj ();
  }

  CssProvider::CssProvider (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  CssProvider::CssProvider (GtkCssProvider* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  CssProvider::CssProvider (CssProvider&& src) noexcept
    : Glib::Object (std::move (src)),
      StyleProvider (std::move (src))
  {
  }

  auto
  CssProvider::operator= (CssProvider&& src) noexcept -> CssProvider&
  {
    Glib::Object::operator= (std::move (src));
    StyleProvider::operator= (std::move (src));
    return *this;
  }

  CssProvider::~CssProvider () noexcept {}

  CssProvider::CppClassType CssProvider::cssprovider_class_;

  auto
  CssProvider::get_type () -> GType
  {
    return cssprovider_class_.init ().get_type ();
  }

  auto
  CssProvider::get_base_type () -> GType
  {
    return gtk_css_provider_get_type ();
  }

  CssProvider::CssProvider ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (cssprovider_class_.init ()))
  {
  }

  auto
  CssProvider::create () -> Glib::RefPtr<CssProvider>
  {
    return Glib::make_refptr_for_instance<CssProvider> (new CssProvider ());
  }

  auto
  CssProvider::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_css_provider_to_string (const_cast<GtkCssProvider*> (gobj ())));
  }

  auto
  CssProvider::load_from_file (const Glib::RefPtr<const Gio::File>& file) -> void
  {
    gtk_css_provider_load_from_file (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)));
  }

  auto
  CssProvider::load_from_path (const std::string& path) -> void
  {
    gtk_css_provider_load_from_path (gobj (), path.c_str ());
  }

  auto
  CssProvider::load_from_resource (const std::string& resource_path) -> void
  {
    gtk_css_provider_load_from_resource (gobj (), resource_path.c_str ());
  }

  auto
  CssProvider::load_named (const Glib::ustring& name,
                           const Glib::ustring& variant) -> void
  {
    gtk_css_provider_load_named (gobj (),
                                 name.c_str (),
                                 variant.empty () ? nullptr : variant.c_str ());
  }

  auto
  CssProvider::signal_parsing_error () -> Glib::SignalProxy<void (const Glib::RefPtr<const CssSection>&,
                                 const Glib::Error&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<const CssSection>&,
                                   const Glib::Error&)> (
        this,
        &CssProvider_signal_parsing_error_info);
  }

} // namespace Gtk
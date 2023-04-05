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
    using namespace gtk;
    typedef sigc::slot<void (const glib::RefPtr<const CssSection>&,
                             const glib::Error&)>
        SlotType;

    auto obj = dynamic_cast<CssProvider*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        glib::Error::throw_exception (g_error_copy (p1));
      }
      catch (const glib::Error& ex)
      {
        try
        {
          if (sigc::slot_base* const slot =
                  glib::SignalProxyNormal::data_to_slot (data))
            (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), ex);
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }
  }

} // namespace

namespace gtk
{

  auto
  CssProvider::load_from_data (const std::string& data) -> void
  {
    gtk_css_provider_load_from_data (gobj (), data.c_str (), -1);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo CssProvider_signal_parsing_error_info = {
      "parsing-error",
      (GCallback) &CssProvider_signal_parsing_error_callback,
      (GCallback) &CssProvider_signal_parsing_error_callback};

}

gtk::CssParserError::CssParserError (gtk::CssParserError::Code error_code,
                                     const glib::ustring& error_message)
  : glib::Error (GTK_CSS_PARSER_ERROR, error_code, error_message)
{
}

gtk::CssParserError::CssParserError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::CssParserError::code () const -> gtk::CssParserError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::CssParserError::throw_func (GError* gobject) -> void
{
  throw gtk::CssParserError (gobject);
}

auto
glib::Value<gtk::CssParserError::Code>::value_type () -> GType
{
  return gtk_css_parser_error_get_type ();
}

gtk::CssParserWarning::CssParserWarning (gtk::CssParserWarning::Code error_code,
                                         const glib::ustring& error_message)
  : glib::Error (GTK_CSS_PARSER_WARNING, error_code, error_message)
{
}

gtk::CssParserWarning::CssParserWarning (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::CssParserWarning::code () const -> gtk::CssParserWarning::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::CssParserWarning::throw_func (GError* gobject) -> void
{
  throw gtk::CssParserWarning (gobject);
}

auto
glib::Value<gtk::CssParserWarning::Code>::value_type () -> GType
{
  return gtk_css_parser_warning_get_type ();
}

namespace glib
{

  auto
  wrap (GtkCssProvider* object, bool take_copy) -> glib::RefPtr<gtk::CssProvider>
  {
    return glib::make_refptr_for_instance<gtk::CssProvider> (
        dynamic_cast<gtk::CssProvider*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  CssProvider_Class::init () -> const glib::Class&
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
  CssProvider_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CssProvider ((GtkCssProvider*) object);
  }

  auto
  CssProvider::gobj_copy () -> GtkCssProvider*
  {
    reference ();
    return gobj ();
  }

  CssProvider::CssProvider (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  CssProvider::CssProvider (GtkCssProvider* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  CssProvider::CssProvider (CssProvider&& src) noexcept
    : glib::Object (std::move (src)),
      StyleProvider (std::move (src))
  {
  }

  auto
  CssProvider::operator= (CssProvider&& src) noexcept -> CssProvider&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (cssprovider_class_.init ()))
  {
  }

  auto
  CssProvider::create () -> glib::RefPtr<CssProvider>
  {
    return glib::make_refptr_for_instance<CssProvider> (new CssProvider ());
  }

  auto
  CssProvider::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_css_provider_to_string (const_cast<GtkCssProvider*> (gobj ())));
  }

  auto
  CssProvider::load_from_file (const glib::RefPtr<const gio::File>& file) -> void
  {
    gtk_css_provider_load_from_file (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)));
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
  CssProvider::load_named (const glib::ustring& name,
                           const glib::ustring& variant) -> void
  {
    gtk_css_provider_load_named (gobj (),
                                 name.c_str (),
                                 variant.empty () ? nullptr : variant.c_str ());
  }

  auto
  CssProvider::signal_parsing_error () -> glib::SignalProxy<void (const glib::RefPtr<const CssSection>&,
                                 const glib::Error&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<const CssSection>&,
                                   const glib::Error&)> (
        this,
        &CssProvider_signal_parsing_error_info);
  }

} // namespace gtk

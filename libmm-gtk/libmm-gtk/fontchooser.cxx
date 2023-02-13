


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontchooser.hxx>
#include <libmm-gtk/fontchooser_p.hxx>


/* Copyright 2011 The gtkmm Development Team
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

#include <gtk/gtk.h>

using Level = Gtk::FontChooser::Level;

namespace
{
extern "C"
{
static auto SignalProxy_Filter_gtk_callback(const PangoFontFamily* family, const PangoFontFace* face, const gpointer user_data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::FontChooser::SlotFontFilter*>(user_data);

  try
  {
    // Create suitable C++ instances to pass to the C++ method:
    const Glib::RefPtr<const Pango::FontFamily> cppFamily = Glib::wrap(const_cast<PangoFontFamily*>(family), true);
    const Glib::RefPtr<const Pango::FontFace> cppFace = Glib::wrap(const_cast<PangoFontFace*>(face), true);
    return (*the_slot)(cppFamily, cppFace);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return false; // arbitrary value
}

static auto SignalProxy_Filter_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::FontChooser::SlotFontFilter*>(data);
}

} // extern "C"
} // anonymous namespace

namespace Gtk
{

auto FontChooser::set_filter_func (const SlotFontFilter &slot) -> void
{
  const auto slot_copy = new SlotFontFilter(slot);
  gtk_font_chooser_set_filter_func(gobj(), &SignalProxy_Filter_gtk_callback, slot_copy, &SignalProxy_Filter_gtk_callback_destroy);
}

} //namespace Gtk

namespace
{


auto FontChooser_signal_font_activated_callback (
  GtkFontChooser *self, const gchar *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<FontChooser*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo FontChooser_signal_font_activated_info =
{
  "font-activated",
  (GCallback) &FontChooser_signal_font_activated_callback,
  (GCallback) &FontChooser_signal_font_activated_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::FontChooser::Level>::value_type() -> GType
{
  return gtk_font_chooser_level_get_type();
}


namespace Glib
{

auto wrap(GtkFontChooser* object, const bool take_copy) -> RefPtr<Gtk::FontChooser>
{
  return Glib::make_refptr_for_instance<Gtk::FontChooser>( Glib::wrap_auto_interface<Gtk::FontChooser> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto FontChooser_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &FontChooser_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_font_chooser_get_type();
  }

  return *this;
}

auto FontChooser_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


  klass->font_activated = &font_activated_callback;
}


auto FontChooser_Class::font_activated_callback (GtkFontChooser *self, const gchar *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_font_activated(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->font_activated)
    (*base->font_activated)(self, p0);
}


auto FontChooser_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FontChooser((GtkFontChooser*)object);
}


/* The implementation: */

FontChooser::FontChooser()
: Interface(fontchooser_class_.init())
{}

FontChooser::FontChooser(GtkFontChooser* castitem)
: Interface((GObject*)castitem)
{}

FontChooser::FontChooser(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

FontChooser::FontChooser(FontChooser&& src) noexcept
: Interface(std::move(src))
{}

auto FontChooser::operator=(FontChooser&& src) noexcept -> FontChooser&
{
  Interface::operator=(std::move(src));
  return *this;
}

FontChooser::~FontChooser() noexcept = default;

// static
auto FontChooser::add_interface (
  const GType gtype_implementer) -> void
{
  fontchooser_class_.init().add_interface(gtype_implementer);
}

FontChooser::CppClassType FontChooser::fontchooser_class_; // initialize static member

auto FontChooser::get_type() -> GType
{
  return fontchooser_class_.init().get_type();
}


auto FontChooser::get_base_type() -> GType
{
  return gtk_font_chooser_get_type();
}


auto FontChooser::get_font_family() -> Glib::RefPtr<Pango::FontFamily>
{
  auto retvalue = Glib::wrap(gtk_font_chooser_get_font_family(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FontChooser::get_font_family() const -> Glib::RefPtr<const Pango::FontFamily>
{
  return const_cast<FontChooser*>(this)->get_font_family();
}

auto FontChooser::get_font_face() -> Glib::RefPtr<Pango::FontFace>
{
  auto retvalue = Glib::wrap(gtk_font_chooser_get_font_face(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FontChooser::get_font_face() const -> Glib::RefPtr<const Pango::FontFace>
{
  return const_cast<FontChooser*>(this)->get_font_face();
}

auto FontChooser::get_font_size() const -> int
{
  return gtk_font_chooser_get_font_size(const_cast<GtkFontChooser*>(gobj()));
}

auto FontChooser::get_font_desc() const -> Pango::FontDescription
{
  return Glib::wrap(gtk_font_chooser_get_font_desc(const_cast<GtkFontChooser*>(gobj())), false);
}

auto FontChooser::set_font_desc (const Pango::FontDescription &font_desc) -> void
{
  gtk_font_chooser_set_font_desc(gobj(), font_desc.gobj());
}

auto FontChooser::get_font() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_font_chooser_get_font(const_cast<GtkFontChooser*>(gobj())));
}

auto FontChooser::set_font (const Glib::ustring &fontname) -> void
{
  gtk_font_chooser_set_font(gobj(), fontname.c_str());
}

auto FontChooser::get_preview_text() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_font_chooser_get_preview_text(const_cast<GtkFontChooser*>(gobj())));
}

auto FontChooser::set_preview_text (const Glib::ustring &text) -> void
{
  gtk_font_chooser_set_preview_text(gobj(), text.c_str());
}

auto FontChooser::get_show_preview_entry() const -> bool
{
  return gtk_font_chooser_get_show_preview_entry(const_cast<GtkFontChooser*>(gobj()));
}

auto FontChooser::set_show_preview_entry (
  const bool show_preview_entry) -> void
{
  gtk_font_chooser_set_show_preview_entry(gobj(), show_preview_entry);
}

auto FontChooser::set_font_map (const Glib::RefPtr <Pango::FontMap> &fontmap) -> void
{
  gtk_font_chooser_set_font_map(gobj(), Glib::unwrap(fontmap));
}

auto FontChooser::get_font_map() -> Glib::RefPtr<Pango::FontMap>
{
  auto retvalue = Glib::wrap(gtk_font_chooser_get_font_map(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FontChooser::get_font_map() const -> Glib::RefPtr<const Pango::FontMap>
{
  return const_cast<FontChooser*>(this)->get_font_map();
}

auto FontChooser::set_level (Level level) -> void
{
  gtk_font_chooser_set_level(gobj(), static_cast<GtkFontChooserLevel>(level));
}

auto FontChooser::get_level() const -> Level
{
  return static_cast<Level>(gtk_font_chooser_get_level(const_cast<GtkFontChooser*>(gobj())));
}

auto FontChooser::get_font_features() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_font_chooser_get_font_features(const_cast<GtkFontChooser*>(gobj())));
}

auto FontChooser::get_language() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_font_chooser_get_language(const_cast<GtkFontChooser*>(gobj())));
}

auto FontChooser::set_language (const Glib::ustring &language) -> void
{
  gtk_font_chooser_set_language(gobj(), language.c_str());
}


auto FontChooser::signal_font_activated() -> Glib::SignalProxy<void(const Glib::ustring&)>
{
  return {this, &FontChooser_signal_font_activated_info};
}


auto FontChooser::property_font() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "font"};
}

auto FontChooser::property_font() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "font"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::FontDescription>::value,
  "Type Pango::FontDescription cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FontChooser::property_font_desc() -> Glib::PropertyProxy< Pango::FontDescription >
{
  return {this, "font-desc"};
}

auto FontChooser::property_font_desc() const -> Glib::PropertyProxy_ReadOnly< Pango::FontDescription >
{
  return {this, "font-desc"};
}

auto FontChooser::property_preview_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "preview-text"};
}

auto FontChooser::property_preview_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "preview-text"};
}

auto FontChooser::property_show_preview_entry() -> Glib::PropertyProxy< bool >
{
  return {this, "show-preview-entry"};
}

auto FontChooser::property_show_preview_entry() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-preview-entry"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Level>::value,
  "Type Level cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FontChooser::property_level() -> Glib::PropertyProxy< Level >
{
  return {this, "level"};
}

auto FontChooser::property_level() const -> Glib::PropertyProxy_ReadOnly< Level >
{
  return {this, "level"};
}

auto FontChooser::property_font_features() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "font-features"};
}

auto FontChooser::property_language() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "language"};
}

auto FontChooser::property_language() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "language"};
}


auto FontChooser::on_font_activated (const Glib::ustring &fontname) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->font_activated)
    (*base->font_activated)(gobj(),fontname.c_str());
}


} // namespace Gtk


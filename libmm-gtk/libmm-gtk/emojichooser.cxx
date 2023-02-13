


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/emojichooser.hxx>
#include <libmm-gtk/emojichooser_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{


auto EmojiChooser_signal_emoji_picked_callback (
  GtkEmojiChooser *self, const gchar *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<EmojiChooser*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo EmojiChooser_signal_emoji_picked_info =
{
  "emoji-picked",
  (GCallback) &EmojiChooser_signal_emoji_picked_callback,
  (GCallback) &EmojiChooser_signal_emoji_picked_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkEmojiChooser* object, const bool take_copy) -> Gtk::EmojiChooser*
{
  return dynamic_cast<Gtk::EmojiChooser *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto EmojiChooser_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EmojiChooser_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_emoji_chooser_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto EmojiChooser_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EmojiChooser_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new EmojiChooser((GtkEmojiChooser*)o));

}


/* The implementation: */

EmojiChooser::EmojiChooser(const Glib::ConstructParams& construct_params)
: Popover(construct_params)
{
  }

EmojiChooser::EmojiChooser(GtkEmojiChooser* castitem)
: Popover((GtkPopover*)castitem)
{
  }


EmojiChooser::EmojiChooser(EmojiChooser&& src) noexcept
: Popover(std::move(src))
{}

auto EmojiChooser::operator=(EmojiChooser&& src) noexcept -> EmojiChooser&
{
  Popover::operator=(std::move(src));
  return *this;
}

EmojiChooser::~EmojiChooser() noexcept
{
  destroy_();
}

EmojiChooser::CppClassType EmojiChooser::emojichooser_class_; // initialize static member

auto EmojiChooser::get_type() -> GType
{
  return emojichooser_class_.init().get_type();
}


auto EmojiChooser::get_base_type() -> GType
{
  return gtk_emoji_chooser_get_type();
}


EmojiChooser::EmojiChooser()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Popover(Glib::ConstructParams(emojichooser_class_.init()))
{


}


auto EmojiChooser::signal_emoji_picked() -> Glib::SignalProxy<void(const Glib::ustring&)>
{
  return {this, &EmojiChooser_signal_emoji_picked_info};
}


} // namespace Gtk



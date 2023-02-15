// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/emojichooser.hxx>
#include <libmm-gtk/emojichooser_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  EmojiChooser_signal_emoji_picked_callback (GtkEmojiChooser* self,
                                             const gchar* p0,
                                             void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    auto obj = dynamic_cast<EmojiChooser*> (
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
  }

  static const Glib::SignalProxyInfo EmojiChooser_signal_emoji_picked_info = {
      "emoji-picked",
      (GCallback) &EmojiChooser_signal_emoji_picked_callback,
      (GCallback) &EmojiChooser_signal_emoji_picked_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkEmojiChooser* object, bool take_copy) -> Gtk::EmojiChooser*
  {
    return dynamic_cast<Gtk::EmojiChooser*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EmojiChooser_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EmojiChooser_Class::class_init_function;

      register_derived_type (gtk_emoji_chooser_get_type ());
    }

    return *this;
  }

  auto
  EmojiChooser_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EmojiChooser_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new EmojiChooser ((GtkEmojiChooser*) (o)));
  }

  EmojiChooser::EmojiChooser (const Glib::ConstructParams& construct_params)
    : Gtk::Popover (construct_params)
  {
  }

  EmojiChooser::EmojiChooser (GtkEmojiChooser* castitem)
    : Gtk::Popover ((GtkPopover*) (castitem))
  {
  }

  EmojiChooser::EmojiChooser (EmojiChooser&& src) noexcept
    : Gtk::Popover (std::move (src))
  {
  }

  auto
  EmojiChooser::operator= (EmojiChooser&& src) noexcept -> EmojiChooser&
  {
    Gtk::Popover::operator= (std::move (src));
    return *this;
  }

  EmojiChooser::~EmojiChooser () noexcept
  {
    destroy_ ();
  }

  EmojiChooser::CppClassType EmojiChooser::emojichooser_class_;

  auto
  EmojiChooser::get_type () -> GType
  {
    return emojichooser_class_.init ().get_type ();
  }

  auto
  EmojiChooser::get_base_type () -> GType
  {
    return gtk_emoji_chooser_get_type ();
  }

  EmojiChooser::EmojiChooser ()
    : Glib::ObjectBase (nullptr),
      Gtk::Popover (Glib::ConstructParams (emojichooser_class_.init ()))
  {
  }

  auto
  EmojiChooser::signal_emoji_picked () -> Glib::SignalProxy<void (const Glib::ustring&)>
  {
    return Glib::SignalProxy<void (const Glib::ustring&)> (
        this,
        &EmojiChooser_signal_emoji_picked_info);
  }

} // namespace Gtk

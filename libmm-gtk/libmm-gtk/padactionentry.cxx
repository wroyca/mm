

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/padactionentry.hxx>
#include <libmm-gtk/padactionentry_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  PadActionEntry::PadActionEntry ()
    : gobject_ (g_new0 (GtkPadActionEntry, 1))
  {
  }

  PadActionEntry::PadActionEntry (PadActionType type,
                                  const int index,
                                  const int mode,
                                  const Glib::ustring& label,
                                  const Glib::ustring& action_name)
    : gobject_ (g_new (GtkPadActionEntry, 1))
  {
    gobject_->type = static_cast<GtkPadActionType> (type);
    gobject_->index = index;
    gobject_->mode = mode;
    gobject_->label = g_strdup (label.c_str ());
    gobject_->action_name = g_strdup (action_name.c_str ());
  }

  PadActionEntry::~PadActionEntry ()
  {
    release_gobject ();
  }

  auto
  PadActionEntry::release_gobject () noexcept -> void
  {
    if (!gobject_)
      return;

    g_free (const_cast<char*> (gobject_->label));
    g_free (const_cast<char*> (gobject_->action_name));
    g_free (gobject_);
    gobject_ = nullptr;
  }

  PadActionEntry::PadActionEntry (const PadActionEntry& src)
    : gobject_ (nullptr)
  {
    operator= (src);
  }

  auto
  PadActionEntry::operator= (const PadActionEntry& src) -> PadActionEntry&
  {
    if (this == &src)
      return *this;

    if (!src.gobject_)
    {
      release_gobject ();
      return *this;
    }

    if (!gobject_)
      gobject_ = g_new (GtkPadActionEntry, 1);
    else
    {
      g_free (const_cast<char*> (gobject_->label));
      g_free (const_cast<char*> (gobject_->action_name));
    }

    *gobject_ = *src.gobject_;

    gobject_->label = g_strdup (src.gobject_->label);
    gobject_->action_name = g_strdup (src.gobject_->action_name);

    return *this;
  }

  PadActionEntry::PadActionEntry (PadActionEntry&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
    other.gobject_ = nullptr;
  }

  auto
  PadActionEntry::operator= (PadActionEntry&& other) noexcept -> PadActionEntry&
  {
    release_gobject ();

    gobject_ = std::move (other.gobject_);
    other.gobject_ = nullptr;

    return *this;
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::PadActionType>::value_type () -> GType
{
  return gtk_pad_action_type_get_type ();
}

namespace Gtk
{

  auto
  PadActionEntry::get_type () const -> PadActionType
  {
    return static_cast<PadActionType> (gobj ()->type);
  }

  auto
  PadActionEntry::set_type (const PadActionType& value) -> void
  {
    gobj ()->type = static_cast<GtkPadActionType> (value);
  }

  auto
  PadActionEntry::get_index () const -> int
  {
    return gobj ()->index;
  }

  auto
  PadActionEntry::set_index (const int& value) -> void
  {
    gobj ()->index = value;
  }

  auto
  PadActionEntry::get_mode () const -> int
  {
    return gobj ()->mode;
  }

  auto
  PadActionEntry::set_mode (const int& value) -> void
  {
    gobj ()->mode = value;
  }

  auto
  PadActionEntry::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (gobj ()->label);
  }

  auto
  PadActionEntry::set_label (const Glib::ustring& value) -> void
  {
    g_free ((char*) gobj ()->label);
    gobj ()->label = g_strdup (value.c_str ());
  }

  auto
  PadActionEntry::get_action_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (gobj ()->action_name);
  }

  auto
  PadActionEntry::set_action_name (const Glib::ustring& value) -> void
  {
    g_free ((char*) gobj ()->action_name);
    gobj ()->action_name = g_strdup (value.c_str ());
  }

} // namespace Gtk

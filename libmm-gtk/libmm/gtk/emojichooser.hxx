// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EMOJICHOOSER_H
#define _GTKMM_EMOJICHOOSER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/popover.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEmojiChooser = struct _GtkEmojiChooser;
using GtkEmojiChooserClass = struct _GtkEmojiChooserClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EmojiChooser_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT EmojiChooser : public Popover
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef EmojiChooser CppObjectType;
    typedef EmojiChooser_Class CppClassType;
    typedef GtkEmojiChooser BaseObjectType;
    typedef GtkEmojiChooserClass BaseClassType;
#endif

    EmojiChooser (EmojiChooser&& src) noexcept;
    auto
    operator= (EmojiChooser&& src) noexcept -> EmojiChooser&;

    EmojiChooser (const EmojiChooser&) = delete;
    auto
    operator= (const EmojiChooser&) -> EmojiChooser& = delete;

    ~EmojiChooser () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class EmojiChooser_Class;
    static CppClassType emojichooser_class_;

  protected:
    explicit EmojiChooser (const glib::ConstructParams& construct_params);
    explicit EmojiChooser (GtkEmojiChooser* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEmojiChooser*
    {
      return reinterpret_cast<GtkEmojiChooser*> (gobject_);
    }

    auto
    gobj () const -> const GtkEmojiChooser*
    {
      return reinterpret_cast<GtkEmojiChooser*> (gobject_);
    }

  private:
  public:
    EmojiChooser ();

    auto
    signal_emoji_picked () -> glib::SignalProxy<void (const glib::ustring&)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEmojiChooser* object, bool take_copy = false) -> gtk::EmojiChooser*;
} // namespace glib

#endif

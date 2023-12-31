// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTCHILDANCHOR_H
#define _GTKMM_TEXTCHILDANCHOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextChildAnchor = struct _GtkTextChildAnchor;
using GtkTextChildAnchorClass = struct _GtkTextChildAnchorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TextChildAnchor_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TextChildAnchor : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TextChildAnchor;
    using CppClassType = TextChildAnchor_Class;
    using BaseObjectType = GtkTextChildAnchor;
    using BaseClassType = GtkTextChildAnchorClass;

    TextChildAnchor (const TextChildAnchor&) = delete;
    auto
    operator= (const TextChildAnchor&) -> TextChildAnchor& = delete;

  private:
    friend class TextChildAnchor_Class;
    static CppClassType textchildanchor_class_;

  protected:
    explicit TextChildAnchor (const glib::ConstructParams& construct_params);
    explicit TextChildAnchor (GtkTextChildAnchor* castitem);

#endif

  public:
    TextChildAnchor (TextChildAnchor&& src) noexcept;
    auto
    operator= (TextChildAnchor&& src) noexcept -> TextChildAnchor&;

    ~TextChildAnchor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTextChildAnchor*
    {
      return reinterpret_cast<GtkTextChildAnchor*> (gobject_);
    }

    auto
    gobj () const -> const GtkTextChildAnchor*
    {
      return reinterpret_cast<GtkTextChildAnchor*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTextChildAnchor*;

  private:
  protected:
    TextChildAnchor ();

  public:
    static auto
    create () -> glib::RefPtr<TextChildAnchor>;

    static auto
    create (const glib::ustring& replacement_character)
        -> glib::RefPtr<TextChildAnchor>;

    auto
    get_widgets () -> std::vector<Widget*>;

    auto
    get_widgets () const -> std::vector<const Widget*>;

    auto
    get_deleted () const -> bool;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextChildAnchor* object, bool take_copy = false) -> glib::RefPtr<gtk::TextChildAnchor>;
} // namespace glib

#endif

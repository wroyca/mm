// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTMARK_H
#define _GTKMM_TEXTMARK_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextMark = struct _GtkTextMark;
using GtkTextMarkClass = struct _GtkTextMarkClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TextMark_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TextBuffer;
  class LIBMM_GTK_SYMEXPORT TextIter;
  class LIBMM_GTK_SYMEXPORT TextConstIter;

  class LIBMM_GTK_SYMEXPORT TextMark : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TextMark;
    using CppClassType = TextMark_Class;
    using BaseObjectType = GtkTextMark;
    using BaseClassType = GtkTextMarkClass;

    TextMark (const TextMark&) = delete;
    auto
    operator= (const TextMark&) -> TextMark& = delete;

  private:
    friend class TextMark_Class;
    static CppClassType textmark_class_;

  protected:
    explicit TextMark (const glib::ConstructParams& construct_params);
    explicit TextMark (GtkTextMark* castitem);

#endif

  public:
    TextMark (TextMark&& src) noexcept;
    auto
    operator= (TextMark&& src) noexcept -> TextMark&;

    ~TextMark () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTextMark*
    {
      return reinterpret_cast<GtkTextMark*> (gobject_);
    }

    auto
    gobj () const -> const GtkTextMark*
    {
      return reinterpret_cast<GtkTextMark*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTextMark*;

  private:
  protected:
    explicit TextMark (bool left_gravity = true);

    explicit TextMark (const glib::ustring& name, bool left_gravity = true);

  public:
    static auto
    create (bool left_gravity = true) -> glib::RefPtr<TextMark>;

    static auto
    create (const glib::ustring& name, bool left_gravity = true)
        -> glib::RefPtr<TextMark>;

    auto
    set_visible (bool setting = true) -> void;

    auto
    get_visible () const -> bool;

    auto
    get_name () const -> glib::ustring;

    auto
    get_deleted () const -> bool;

    auto
    get_buffer () -> glib::RefPtr<TextBuffer>;

    auto
    get_buffer () const -> glib::RefPtr<const TextBuffer>;

    auto
    get_left_gravity () const -> bool;

    auto
    get_iter () -> TextIter;
    auto
    get_iter () const -> TextConstIter;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_left_gravity () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextMark* object, bool take_copy = false) -> glib::RefPtr<gtk::TextMark>;
} // namespace glib

#endif

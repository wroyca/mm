// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTTAGTABLE_H
#define _GTKMM_TEXTTAGTABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/texttag.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextTagTable = struct _GtkTextTagTable;
using GtkTextTagTableClass = struct _GtkTextTagTableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TextTagTable_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TextTag;

  class LIBMM_GTK_SYMEXPORT TextTagTable : public Glib::Object,
                                 public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TextTagTable;
    using CppClassType = TextTagTable_Class;
    using BaseObjectType = GtkTextTagTable;
    using BaseClassType = GtkTextTagTableClass;

    TextTagTable (const TextTagTable&) = delete;
    auto
    operator= (const TextTagTable&) -> TextTagTable& = delete;

  private:
    friend class TextTagTable_Class;
    static CppClassType texttagtable_class_;

  protected:
    explicit TextTagTable (const Glib::ConstructParams& construct_params);
    explicit TextTagTable (GtkTextTagTable* castitem);

#endif

  public:
    TextTagTable (TextTagTable&& src) noexcept;
    auto
    operator= (TextTagTable&& src) noexcept -> TextTagTable&;

    ~TextTagTable () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTextTagTable*
    {
      return reinterpret_cast<GtkTextTagTable*> (gobject_);
    }

    auto
    gobj () const -> const GtkTextTagTable*
    {
      return reinterpret_cast<GtkTextTagTable*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTextTagTable*;

  private:
  protected:
    TextTagTable ();

  public:
    static auto
    create () -> Glib::RefPtr<TextTagTable>;

    auto
    add (const Glib::RefPtr<TextTag>& tag) -> bool;

    auto
    remove (const Glib::RefPtr<TextTag>& tag) -> void;

    auto
    lookup (const Glib::ustring& name) -> Glib::RefPtr<TextTag>;

    auto
    lookup (const Glib::ustring& name) const -> Glib::RefPtr<const TextTag>;

    typedef sigc::slot<void (const Glib::RefPtr<TextTag>&)> SlotForEach;
    auto foreach (const SlotForEach& slot) -> void;

    auto
    get_size () const -> int;

    auto
    signal_tag_changed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TextTag>&, bool)>;

    auto
    signal_tag_added ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TextTag>&)>;

    auto
    signal_tag_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TextTag>&)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextTagTable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextTagTable>;
} // namespace Glib

#endif

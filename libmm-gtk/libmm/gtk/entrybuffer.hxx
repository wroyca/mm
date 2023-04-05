// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENTRYBUFFER_H
#define _GTKMM_ENTRYBUFFER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/mm-gtkconfig.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntryBuffer = struct _GtkEntryBuffer;
using GtkEntryBufferClass = struct _GtkEntryBufferClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EntryBuffer_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT EntryBuffer : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EntryBuffer;
    using CppClassType = EntryBuffer_Class;
    using BaseObjectType = GtkEntryBuffer;
    using BaseClassType = GtkEntryBufferClass;

    EntryBuffer (const EntryBuffer&) = delete;
    auto
    operator= (const EntryBuffer&) -> EntryBuffer& = delete;

  private:
    friend class EntryBuffer_Class;
    static CppClassType entrybuffer_class_;

  protected:
    explicit EntryBuffer (const glib::ConstructParams& construct_params);
    explicit EntryBuffer (GtkEntryBuffer* castitem);

#endif

  public:
    EntryBuffer (EntryBuffer&& src) noexcept;
    auto
    operator= (EntryBuffer&& src) noexcept -> EntryBuffer&;

    ~EntryBuffer () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEntryBuffer*
    {
      return reinterpret_cast<GtkEntryBuffer*> (gobject_);
    }

    auto
    gobj () const -> const GtkEntryBuffer*
    {
      return reinterpret_cast<GtkEntryBuffer*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEntryBuffer*;

  private:
  protected:
    EntryBuffer ();

    explicit EntryBuffer (const glib::ustring& text);

  public:
    static auto
    create () -> glib::RefPtr<EntryBuffer>;

    static auto
    create (const glib::ustring& text) -> glib::RefPtr<EntryBuffer>;

    auto
    get_bytes () const -> gsize;

    auto
    get_length () const -> guint;

    auto
    get_text () const -> glib::ustring;

    auto
    set_text (const glib::ustring& text) -> void;

    auto
    set_max_length (int max_length) -> void;

    auto
    get_max_length () const -> int;

    auto
    insert_text (guint position, const glib::ustring& text) -> guint;

    auto
    delete_text (guint position, int n_chars) -> guint;

    auto
    emit_inserted_text (guint position, const glib::ustring& text) -> void;

    auto
    emit_deleted_text (guint position, guint n_chars) -> void;

    auto
    signal_inserted_text ()
        -> glib::SignalProxy<void (guint, const char*, guint)>;

    auto
    signal_deleted_text () -> glib::SignalProxy<void (guint, guint)>;

    auto
    property_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_length () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_max_length () -> glib::PropertyProxy<int>;

    auto
    property_max_length () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual auto
    on_inserted_text (guint position, const char* chars, guint n_chars) -> void;

    virtual auto
    on_deleted_text (guint position, guint n_chars) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEntryBuffer* object, bool take_copy = false) -> glib::RefPtr<gtk::EntryBuffer>;
} // namespace glib

#endif

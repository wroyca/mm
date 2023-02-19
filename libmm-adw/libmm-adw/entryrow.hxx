// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENTRYROW_H
#define _LIBADWAITAMM_ENTRYROW_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/preferencesrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT EntryRow_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT EntryRow : public Adw::PreferencesRow,
                   public Gtk::Editable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef EntryRow CppObjectType;
    typedef EntryRow_Class CppClassType;
    typedef AdwEntryRow BaseObjectType;
    typedef AdwEntryRowClass BaseClassType;
#endif

    EntryRow (EntryRow&& src) noexcept;
    auto
    operator= (EntryRow&& src) noexcept -> EntryRow&;

    EntryRow (const EntryRow&) = delete;
    auto
    operator= (const EntryRow&) -> EntryRow& = delete;

    ~EntryRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class EntryRow_Class;
    static CppClassType entryrow_class_;

  protected:
    explicit EntryRow (const Glib::ConstructParams& construct_params);
    explicit EntryRow (AdwEntryRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwEntryRow*
    {
      return reinterpret_cast<AdwEntryRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwEntryRow*
    {
      return reinterpret_cast<AdwEntryRow*> (gobject_);
    }

  private:
  public:
    EntryRow ();

    auto
    add_prefix (Gtk::Widget* widget) -> void;

    auto
    add_suffix (Gtk::Widget* widget) -> void;

    auto
    get_activates_default () const -> bool;

    auto
    get_attributes () const -> Pango::AttrList;

    auto
    get_enable_moji_completion () const -> bool;

    auto
    get_input_hints () const -> Gtk::InputHints;

    auto
    get_input_purpose () const -> Gtk::InputPurpose;

    auto
    get_show_apply_button () const -> bool;

    auto
    remove (Gtk::Widget* widget) -> void;

    auto
    set_activates_default (bool activates) -> void;

    auto
    set_attributes (Pango::AttrList& attributes) -> void;

    auto
    set_enable_emoji_completion (bool activates) -> void;

    auto
    set_input_hints (Gtk::InputHints hints) -> void;

    auto
    set_input_purpose (Gtk::InputPurpose purpose) -> void;

    auto
    set_show_apply_button (bool activates) -> void;

    auto
    property_activates_default () -> Glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_attributes () -> Glib::PropertyProxy<Pango::AttrList>;

    auto
    property_attributes () const
        -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>;

    auto
    property_enable_emoji_completion () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_input_hints () -> Glib::PropertyProxy<Gtk::InputHints>;

    auto
    property_input_hints () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::InputHints>;

    auto
    property_input_purpose () -> Glib::PropertyProxy<Gtk::InputPurpose>;

    auto
    property_input_purpose () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::InputPurpose>;

    auto
    property_show_apply_button () -> Glib::PropertyProxy<bool>;

    auto
    property_show_apply_button () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_apply () -> Glib::SignalProxy<void ()>;

    auto
    signal_entry_activated () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwEntryRow* object, bool take_copy = false) -> Adw::EntryRow*;
}

#endif

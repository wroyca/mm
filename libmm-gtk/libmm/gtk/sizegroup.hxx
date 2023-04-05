// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SIZEGROUP_H
#define _GTKMM_SIZEGROUP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSizeGroup = struct _GtkSizeGroup;
using GtkSizeGroupClass = struct _GtkSizeGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SizeGroup_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SizeGroup : public glib::Object,
                              public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SizeGroup;
    using CppClassType = SizeGroup_Class;
    using BaseObjectType = GtkSizeGroup;
    using BaseClassType = GtkSizeGroupClass;

    SizeGroup (const SizeGroup&) = delete;
    auto
    operator= (const SizeGroup&) -> SizeGroup& = delete;

  private:
    friend class SizeGroup_Class;
    static CppClassType sizegroup_class_;

  protected:
    explicit SizeGroup (const glib::ConstructParams& construct_params);
    explicit SizeGroup (GtkSizeGroup* castitem);

#endif

  public:
    SizeGroup (SizeGroup&& src) noexcept;
    auto
    operator= (SizeGroup&& src) noexcept -> SizeGroup&;

    ~SizeGroup () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSizeGroup*
    {
      return reinterpret_cast<GtkSizeGroup*> (gobject_);
    }

    auto
    gobj () const -> const GtkSizeGroup*
    {
      return reinterpret_cast<GtkSizeGroup*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSizeGroup*;

  private:
  public:
    enum class Mode
    {
      NONE,
      HORIZONTAL,
      VERTICAL,
      BOTH
    };

  protected:
    explicit SizeGroup (Mode mode);

  public:
    static auto
    create (Mode mode) -> glib::RefPtr<SizeGroup>;

    auto
    set_mode (Mode mode) -> void;

    auto
    get_mode () const -> Mode;

    auto
    add_widget (Widget& widget) -> void;

    auto
    remove_widget (Widget& widget) -> void;

    auto
    get_widgets () -> std::vector<Widget*>;

    auto
    get_widgets () const -> std::vector<const Widget*>;

    auto
    property_mode () -> glib::PropertyProxy<Mode>;

    auto
    property_mode () const -> glib::PropertyProxy_ReadOnly<Mode>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SizeGroup::Mode>
    : public glib::Value_Enum<gtk::SizeGroup::Mode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSizeGroup* object, bool take_copy = false) -> glib::RefPtr<gtk::SizeGroup>;
} // namespace glib

#endif

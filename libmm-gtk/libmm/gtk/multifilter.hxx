// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MULTIFILTER_H
#define _GTKMM_MULTIFILTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/filter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMultiFilter = struct _GtkMultiFilter;
using GtkMultiFilterClass = struct _GtkMultiFilterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT MultiFilter_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAnyFilter = struct _GtkAnyFilter;
using GtkAnyFilterClass = struct _GtkAnyFilterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT AnyFilter_Class;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEveryFilter = struct _GtkEveryFilter;
using GtkEveryFilterClass = struct _GtkEveryFilterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT EveryFilter_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT MultiFilter : public Filter,
                                public Gio::ListModel,
                                public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MultiFilter;
    using CppClassType = MultiFilter_Class;
    using BaseObjectType = GtkMultiFilter;
    using BaseClassType = GtkMultiFilterClass;

    MultiFilter (const MultiFilter&) = delete;
    auto
    operator= (const MultiFilter&) -> MultiFilter& = delete;

  private:
    friend class MultiFilter_Class;
    static CppClassType multifilter_class_;

  protected:
    explicit MultiFilter (const Glib::ConstructParams& construct_params);
    explicit MultiFilter (GtkMultiFilter* castitem);

#endif

  public:
    MultiFilter (MultiFilter&& src) noexcept;
    auto
    operator= (MultiFilter&& src) noexcept -> MultiFilter&;

    ~MultiFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMultiFilter*
    {
      return reinterpret_cast<GtkMultiFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkMultiFilter*
    {
      return reinterpret_cast<GtkMultiFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMultiFilter*;

  private:
  protected:
    MultiFilter ();

  public:
    auto
    append (const Glib::RefPtr<Filter>& filter) -> void;

    auto
    remove (guint position) -> void;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

  class LIBMM_GTK_SYMEXPORT AnyFilter : public MultiFilter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AnyFilter;
    using CppClassType = AnyFilter_Class;
    using BaseObjectType = GtkAnyFilter;
    using BaseClassType = GtkAnyFilterClass;

    AnyFilter (const AnyFilter&) = delete;
    auto
    operator= (const AnyFilter&) -> AnyFilter& = delete;

  private:
    friend class AnyFilter_Class;
    static CppClassType anyfilter_class_;

  protected:
    explicit AnyFilter (const Glib::ConstructParams& construct_params);
    explicit AnyFilter (GtkAnyFilter* castitem);

#endif

  public:
    AnyFilter (AnyFilter&& src) noexcept;
    auto
    operator= (AnyFilter&& src) noexcept -> AnyFilter&;

    ~AnyFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAnyFilter*
    {
      return reinterpret_cast<GtkAnyFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkAnyFilter*
    {
      return reinterpret_cast<GtkAnyFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkAnyFilter*;

  private:
  protected:
    AnyFilter ();

  public:
    static auto
    create () -> Glib::RefPtr<AnyFilter>;

  public:
  public:
  protected:
  };

  class LIBMM_GTK_SYMEXPORT EveryFilter : public MultiFilter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EveryFilter;
    using CppClassType = EveryFilter_Class;
    using BaseObjectType = GtkEveryFilter;
    using BaseClassType = GtkEveryFilterClass;

    EveryFilter (const EveryFilter&) = delete;
    auto
    operator= (const EveryFilter&) -> EveryFilter& = delete;

  private:
    friend class EveryFilter_Class;
    static CppClassType everyfilter_class_;

  protected:
    explicit EveryFilter (const Glib::ConstructParams& construct_params);
    explicit EveryFilter (GtkEveryFilter* castitem);

#endif

  public:
    EveryFilter (EveryFilter&& src) noexcept;
    auto
    operator= (EveryFilter&& src) noexcept -> EveryFilter&;

    ~EveryFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEveryFilter*
    {
      return reinterpret_cast<GtkEveryFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkEveryFilter*
    {
      return reinterpret_cast<GtkEveryFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEveryFilter*;

  private:
  protected:
    EveryFilter ();

  public:
    static auto
    create () -> Glib::RefPtr<EveryFilter>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMultiFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MultiFilter>;
} // namespace Glib

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAnyFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AnyFilter>;
} // namespace Glib

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEveryFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EveryFilter>;
} // namespace Glib

#endif

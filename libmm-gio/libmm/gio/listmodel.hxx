// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_LISTMODEL_H
#define _GIOMM_LISTMODEL_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GListModelInterface GListModelInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GListModel = struct _GListModel;
using GListModelClass = struct _GListModelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ListModel_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ListModel : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ListModel;
    using CppClassType = ListModel_Class;
    using BaseObjectType = GListModel;
    using BaseClassType = GListModelInterface;

    ListModel (const ListModel&) = delete;
    auto
    operator= (const ListModel&) -> ListModel& = delete;

  private:
    friend class ListModel_Class;
    static CppClassType listmodel_class_;

#endif
  protected:
    ListModel ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ListModel (const glib::Interface_Class& interface_class);

  public:
    explicit ListModel (GListModel* castitem);

  protected:
#endif

  public:
    ListModel (ListModel&& src) noexcept;
    auto
    operator= (ListModel&& src) noexcept -> ListModel&;

    ~ListModel () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GListModel*
    {
      return reinterpret_cast<GListModel*> (gobject_);
    }

    auto
    gobj () const -> const GListModel*
    {
      return reinterpret_cast<GListModel*> (gobject_);
    }

  private:
  protected:
    auto
    items_changed (guint position, guint removed, guint added) -> void;

  public:
    auto
    get_item_type () const -> GType;

    auto
    get_n_items () const -> guint;

    auto
    get_object (guint position) -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_object (guint position) const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    signal_items_changed () -> glib::SignalProxy<void (guint, guint, guint)>;

  protected:
    virtual auto
    get_item_type_vfunc () -> GType;

    virtual auto
    get_n_items_vfunc () -> guint;

    virtual auto
    get_item_vfunc (guint position) -> gpointer;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GListModel* object, bool take_copy = false) -> glib::RefPtr<gio::ListModel>;

} // namespace glib

#endif

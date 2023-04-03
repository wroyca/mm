// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_SIGNALPROXY_H
#define _GLIBMM_SIGNALPROXY_H

extern "C"
{
  typedef void (*GCallback) ();
  typedef struct _GObject GObject;
}

#include <libmm/glib/signalproxy_connectionnode.hxx>
#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>
#include <utility>

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT ObjectBase;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  struct SignalProxyInfo
  {
    const char* signal_name;
    GCallback callback;
    GCallback notify_callback;
  };

#endif

  class LIBMM_GLIB_SYMEXPORT SignalProxyBase
  {
  public:
    SignalProxyBase (Glib::ObjectBase* obj);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static inline auto
    data_to_slot (void* data) -> sigc::slot_base*
    {
      const auto pConnectionNode =
          static_cast<SignalProxyConnectionNode*> (data);

      return (!pConnectionNode->slot_.blocked ()) ? &pConnectionNode->slot_ :
                                                    nullptr;
    }
#endif

  protected:
    ObjectBase* obj_;

  private:
    auto
    operator= (const SignalProxyBase&) -> SignalProxyBase& = delete;
  };

  class LIBMM_GLIB_SYMEXPORT SignalProxyNormal : public SignalProxyBase
  {
  public:
    ~SignalProxyNormal () noexcept;

    auto
    emission_stop () -> void;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    slot0_void_callback (GObject*, void* data) -> void;
#endif

  protected:
    SignalProxyNormal (Glib::ObjectBase* obj, const SignalProxyInfo* info);

    auto
    connect_impl_ (bool notify, const sigc::slot_base& slot, bool after)
        -> sigc::slot_base&;

    auto
    connect_impl_ (bool notify, sigc::slot_base&& slot, bool after)
        -> sigc::slot_base&;

  private:
    const SignalProxyInfo* info_;

    auto
    operator= (const SignalProxyNormal&) -> SignalProxyNormal& = delete;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <class R, class... T>
  class SignalProxy;
#endif

  template <class R, class... T>
  class SignalProxy<R (T...)> : public SignalProxyNormal
  {
  public:
    using SlotType = sigc::slot<R (T...)>;
    using VoidSlotType = sigc::slot<void (T...)>;

    SignalProxy (ObjectBase* obj, const SignalProxyInfo* info)
      : SignalProxyNormal (obj, info)
    {
    }

    auto
    connect (const SlotType& slot, bool after) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, slot, after));
    }

    auto
    connect (SlotType&& slot, bool after) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, std::move (slot), after));
    }

    auto
    connect_notify (const VoidSlotType& slot, bool after = false)
        -> sigc::connection
    {
      return sigc::connection (connect_impl_ (true, slot, after));
    }

    auto
    connect_notify (VoidSlotType&& slot, bool after = false) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (true, std::move (slot), after));
    }
  };

  template <class... T>
  class SignalProxy<void (T...)> : public SignalProxyNormal
  {
  public:
    using SlotType = sigc::slot<void (T...)>;

    SignalProxy (ObjectBase* obj, const SignalProxyInfo* info)
      : SignalProxyNormal (obj, info)
    {
    }

    auto
    connect (const SlotType& slot, bool after = true) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, slot, after));
    }

    auto
    connect (SlotType&& slot, bool after = true) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, std::move (slot), after));
    }
  };

  class LIBMM_GLIB_SYMEXPORT SignalProxyDetailedBase : public SignalProxyBase
  {
  public:
    ~SignalProxyDetailedBase () noexcept;

    auto
    emission_stop () -> void;

  protected:
    SignalProxyDetailedBase (Glib::ObjectBase* obj,
                             const SignalProxyInfo* info,
                             const Glib::ustring& detail_name);

    auto
    connect_impl_ (bool notify, const sigc::slot_base& slot, bool after)
        -> sigc::slot_base&;

    auto
    connect_impl_ (bool notify, sigc::slot_base&& slot, bool after)
        -> sigc::slot_base&;

  private:
    const SignalProxyInfo* info_;
    const Glib::ustring detailed_name_;

    auto
    operator= (const SignalProxyDetailedBase&)
        -> SignalProxyDetailedBase& = delete;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <class R, class... T>
  class SignalProxyDetailed;
#endif

  template <class R, class... T>
  class SignalProxyDetailed<R (T...)> : public SignalProxyDetailedBase
  {
  public:
    using SlotType = sigc::slot<R (T...)>;
    using VoidSlotType = sigc::slot<void (T...)>;

    SignalProxyDetailed (ObjectBase* obj,
                         const SignalProxyInfo* info,
                         const Glib::ustring& detail_name)
      : SignalProxyDetailedBase (obj, info, detail_name)
    {
    }

    auto
    connect (const SlotType& slot, bool after) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, slot, after));
    }

    auto
    connect (SlotType&& slot, bool after) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, std::move (slot), after));
    }

    auto
    connect_notify (const VoidSlotType& slot, bool after = false)
        -> sigc::connection
    {
      return sigc::connection (connect_impl_ (true, slot, after));
    }

    auto
    connect_notify (VoidSlotType&& slot, bool after = false) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (true, std::move (slot), after));
    }
  };

  template <class... T>
  class SignalProxyDetailed<void (T...)> : public SignalProxyDetailedBase
  {
  public:
    using SlotType = sigc::slot<void (T...)>;

    SignalProxyDetailed (ObjectBase* obj,
                         const SignalProxyInfo* info,
                         const Glib::ustring& detail_name)
      : SignalProxyDetailedBase (obj, info, detail_name)
    {
    }

    auto
    connect (const SlotType& slot, bool after = true) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, slot, after));
    }

    auto
    connect (SlotType&& slot, bool after = true) -> sigc::connection
    {
      return sigc::connection (connect_impl_ (false, std::move (slot), after));
    }
  };

} // namespace Glib

#endif

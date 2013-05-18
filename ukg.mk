# Inherit AOSP device configuration for crespo.
$(call inherit-product, device/samsung/crespo/full_crespo.mk)

# Inherit common product files.
$(call inherit-product, vendor/aosp/config/common.mk)

# Inherit GSM common stuff
$(call inherit-product, vendor/aosp/config/gsm.mk)

# Crespo Overlay
PRODUCT_PACKAGE_OVERLAYS += vendor/aosp/overlay/crespo

# Setup device specific product configuration.
PRODUCT_NAME := xylon_crespo
PRODUCT_BRAND := google
PRODUCT_DEVICE := crespo
PRODUCT_MODEL := Nexus S
PRODUCT_MANUFACTURER := samsung

PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=soju BUILD_ID=JOP40D BUILD_FINGERPRINT="google/soju/crespo:4.2.1/JOP40D/533553:user/release-keys" PRIVATE_BUILD_DESC="soju-user 4.2.1 JOP40D 533553 release-keys" BUILD_NUMBER=533553

# Copy maguro specific prebuilt files
PRODUCT_COPY_FILES +=  \
    vendor/aosp/prebuilt/hybrid_hdpi.conf:system/etc/beerbong/properties.conf \
    vendor/aosp/prebuilt/common/media/LMprec_508.emd:system/media/LMprec_508.emd \
    vendor/aosp/prebuilt/common/media/PFFprec_600.emd:system/media/PFFprec_600.emd


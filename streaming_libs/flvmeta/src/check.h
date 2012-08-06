/*
    $Id: check.h 231 2011-06-27 13:46:19Z marc.noirot $

    FLV Metadata updater

    Copyright (C) 2007-2012 Marc Noirot <marc.noirot AT gmail.com>

    This file is part of FLVMeta.

    FLVMeta is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLVMeta is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLVMeta; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/
#ifndef __CHECK_H__
#define __CHECK_H__

#include "flvmeta.h"

/* message level codes */
#define LEVEL_FATAL     "F"
#define LEVEL_ERROR     "E"
#define LEVEL_WARNING   "W"
#define LEVEL_INFO      "I"

/* message topic codes */
#define TOPIC_GENERAL_FORMAT    "10"
#define TOPIC_HEADER            "11"
#define TOPIC_PREV_TAG_SIZE     "12"
#define TOPIC_TAG_FORMAT        "20"
#define TOPIC_TAG_TYPES         "30"
#define TOPIC_TIMESTAMPS        "40"
#define TOPIC_AUDIO_DATA        "50"
#define TOPIC_AUDIO_CODECS      "51"
#define TOPIC_VIDEO_DATA        "60"
#define TOPIC_VIDEO_CODECS      "61"
#define TOPIC_METADATA          "70"
#define TOPIC_AMF_DATA          "80"
#define TOPIC_KEYFRAMES         "81"
#define TOPIC_CUE_POINTS        "82"

/* info, warning, error codes, sorted by unique identifier */
#define FATAL_HEADER_EOF                    LEVEL_FATAL     TOPIC_HEADER            "001"
#define FATAL_HEADER_NO_SIGNATURE           LEVEL_FATAL     TOPIC_HEADER            "002"
#define ERROR_HEADER_BAD_VERSION            LEVEL_ERROR     TOPIC_HEADER            "003"
#define ERROR_HEADER_NO_STREAMS             LEVEL_ERROR     TOPIC_HEADER            "004"
#define INFO_HEADER_NO_AUDIO                LEVEL_INFO      TOPIC_HEADER            "005"
#define WARNING_HEADER_NO_VIDEO             LEVEL_WARNING   TOPIC_HEADER            "006"
#define ERROR_HEADER_BAD_RESERVED_FLAGS     LEVEL_ERROR     TOPIC_HEADER            "007"
#define ERROR_HEADER_BAD_OFFSET             LEVEL_ERROR     TOPIC_HEADER            "008"
#define FATAL_PREV_TAG_SIZE_EOF             LEVEL_FATAL     TOPIC_PREV_TAG_SIZE     "009"
#define ERROR_PREV_TAG_SIZE_BAD_FIRST       LEVEL_ERROR     TOPIC_PREV_TAG_SIZE     "010"
#define FATAL_GENERAL_NO_TAG                LEVEL_FATAL     TOPIC_GENERAL_FORMAT    "011"
#define FATAL_TAG_EOF                       LEVEL_FATAL     TOPIC_TAG_FORMAT        "012"
#define ERROR_TAG_TYPE_UNKNOWN              LEVEL_ERROR     TOPIC_TAG_TYPES         "013"
#define WARNING_HEADER_UNEXPECTED_VIDEO     LEVEL_WARNING   TOPIC_HEADER            "014"
#define WARNING_HEADER_UNEXPECTED_AUDIO     LEVEL_WARNING   TOPIC_HEADER            "015"
#define FATAL_TAG_BODY_LENGTH_OVERFLOW      LEVEL_FATAL     TOPIC_TAG_FORMAT        "016"
#define WARNING_TAG_BODY_LENGTH_LARGE       LEVEL_WARNING   TOPIC_TAG_FORMAT        "017"
#define WARNING_TAG_BODY_LENGTH_ZERO        LEVEL_WARNING   TOPIC_TAG_FORMAT        "018"
#define ERROR_TIMESTAMP_FIRST_NON_ZERO      LEVEL_ERROR     TOPIC_TIMESTAMPS        "019"
#define ERROR_TIMESTAMP_AUDIO_DECREASE      LEVEL_ERROR     TOPIC_TIMESTAMPS        "020"
#define ERROR_TIMESTAMP_VIDEO_DECREASE      LEVEL_ERROR     TOPIC_TIMESTAMPS        "021"
#define ERROR_TIMESTAMP_OVERFLOW            LEVEL_ERROR     TOPIC_TIMESTAMPS        "022"
#define ERROR_TIMESTAMP_DECREASE            LEVEL_ERROR     TOPIC_TIMESTAMPS        "023"
#define WARNING_TIMESTAMP_DESYNC            LEVEL_WARNING   TOPIC_TIMESTAMPS        "024"
#define ERROR_TAG_STREAM_ID_NON_ZERO        LEVEL_ERROR     TOPIC_TAG_FORMAT        "025"
#define WARNING_AUDIO_FORMAT_CHANGED        LEVEL_WARNING   TOPIC_AUDIO_DATA        "026"
#define WARNING_AUDIO_CODEC_UNKNOWN         LEVEL_WARNING   TOPIC_AUDIO_CODECS      "027"
#define WARNING_AUDIO_CODEC_RESERVED        LEVEL_WARNING   TOPIC_AUDIO_CODECS      "028"
#define WARNING_AUDIO_CODEC_AAC_BAD         LEVEL_WARNING   TOPIC_AUDIO_CODECS      "029"
#define WARNING_AUDIO_CODEC_NELLYMOSER_BAD  LEVEL_WARNING   TOPIC_AUDIO_CODECS      "030"
#define WARNING_AUDIO_CODEC_AAC_MONO        LEVEL_WARNING   TOPIC_AUDIO_CODECS      "031"
#define WARNING_AUDIO_CODEC_LINEAR_PCM      LEVEL_WARNING   TOPIC_AUDIO_CODECS      "032"
#define WARNING_VIDEO_FORMAT_CHANGED        LEVEL_WARNING   TOPIC_VIDEO_DATA        "033"
#define ERROR_VIDEO_FRAME_TYPE_UNKNOWN      LEVEL_ERROR     TOPIC_VIDEO_DATA        "034"
#define WARNING_VIDEO_NO_FIRST_KEYFRAME     LEVEL_WARNING   TOPIC_VIDEO_DATA        "035"
#define ERROR_VIDEO_CODEC_UNKNOWN           LEVEL_ERROR     TOPIC_VIDEO_CODECS      "036"
#define WARNING_VIDEO_CODEC_JPEG            LEVEL_WARNING   TOPIC_VIDEO_CODECS      "037"
#define WARNING_METADATA_EMPTY              LEVEL_WARNING   TOPIC_METADATA          "038"
#define ERROR_METADATA_NAME_INVALID         LEVEL_ERROR     TOPIC_METADATA          "039"
#define ERROR_METADATA_DATA_INVALID         LEVEL_ERROR     TOPIC_METADATA          "040"
#define ERROR_METADATA_NAME_INVALID_TYPE    LEVEL_ERROR     TOPIC_METADATA          "041"
#define WARNING_METADATA_NAME_EMPTY         LEVEL_WARNING   TOPIC_METADATA          "042"
#define WARNING_METADATA_DATA_REMAINING     LEVEL_WARNING   TOPIC_METADATA          "043"
#define WARNING_METADATA_DATA_MISSING       LEVEL_WARNING   TOPIC_METADATA          "044"
#define WARNING_METADATA_LAST_SECOND_DUP    LEVEL_WARNING   TOPIC_METADATA          "045"
#define ERROR_METADATA_DATA_INVALID_TYPE    LEVEL_ERROR     TOPIC_METADATA          "046"
#define WARNING_METADATA_BAD_TAG            LEVEL_WARNING   TOPIC_METADATA          "047"
#define WARNING_METADATA_BAD_TIMESTAMP      LEVEL_WARNING   TOPIC_METADATA          "048"
#define WARNING_METADATA_DUPLICATE          LEVEL_WARNING   TOPIC_METADATA          "049"
#define INFO_METADATA_NAME_UNKNOWN          LEVEL_INFO      TOPIC_METADATA          "050"
#define ERROR_PREV_TAG_SIZE_BAD             LEVEL_ERROR     TOPIC_PREV_TAG_SIZE     "051"
#define WARNING_HEADER_VIDEO_NOT_FOUND      LEVEL_WARNING   TOPIC_HEADER            "052"
#define WARNING_HEADER_AUDIO_NOT_FOUND      LEVEL_WARNING   TOPIC_HEADER            "053"
#define WARNING_TIMESTAMP_VIDEO_ENDS_FIRST  LEVEL_WARNING   TOPIC_TIMESTAMPS        "054"
#define WARNING_TIMESTAMP_AUDIO_ENDS_FIRST  LEVEL_WARNING   TOPIC_TIMESTAMPS        "055"
#define WARNING_VIDEO_NO_KEYFRAME           LEVEL_WARNING   TOPIC_VIDEO_DATA        "056"
#define WARNING_VIDEO_ONLY_KEYFRAMES        LEVEL_WARNING   TOPIC_VIDEO_DATA        "057"
#define WARNING_VIDEO_ONLY_KF_LAST_SEC      LEVEL_WARNING   TOPIC_VIDEO_DATA        "058"
#define WARNING_METADATA_LAST_SECOND_BAD    LEVEL_WARNING   TOPIC_METADATA          "059"
#define WARNING_METADATA_NOT_PRESENT        LEVEL_WARNING   TOPIC_METADATA          "060"
#define FATAL_INFO_COMPUTATION_ERROR        LEVEL_FATAL     TOPIC_GENERAL_FORMAT    "061"
#define WARNING_AMF_DATA_INVALID_VALUE      LEVEL_WARNING   TOPIC_AMF_DATA          "062"
#define WARNING_AMF_DATA_INVALID_TYPE       LEVEL_WARNING   TOPIC_AMF_DATA          "063"
#define WARNING_AMF_DATA_VIDEO_NEEDED       LEVEL_WARNING   TOPIC_AMF_DATA          "064"
#define WARNING_AMF_DATA_AUDIO_NEEDED       LEVEL_WARNING   TOPIC_AMF_DATA          "065"
#define WARNING_AMF_DATA_AUDIO_VIDEO_NEEDED LEVEL_WARNING   TOPIC_AMF_DATA          "066"
#define WARNING_KEYFRAMES_TIMES_MISSING     LEVEL_WARNING   TOPIC_KEYFRAMES         "067"
#define WARNING_KEYFRAMES_FILEPOS_MISSING   LEVEL_WARNING   TOPIC_KEYFRAMES         "068"
#define WARNING_KEYFRAMES_TIMES_TYPE_BAD    LEVEL_WARNING   TOPIC_KEYFRAMES         "069"
#define WARNING_KEYFRAMES_FILEPOS_TYPE_BAD  LEVEL_WARNING   TOPIC_KEYFRAMES         "070"
#define WARNING_KEYFRAMES_ARRAY_LENGTH_BAD  LEVEL_WARNING   TOPIC_KEYFRAMES         "071"
#define WARNING_KEYFRAMES_TIME_TYPE_BAD     LEVEL_WARNING   TOPIC_KEYFRAMES         "072"
#define WARNING_KEYFRAMES_POS_TYPE_BAD      LEVEL_WARNING   TOPIC_KEYFRAMES         "073"
#define WARNING_KEYFRAMES_TIME_BAD          LEVEL_WARNING   TOPIC_KEYFRAMES         "074"
#define WARNING_KEYFRAMES_POS_BAD           LEVEL_WARNING   TOPIC_KEYFRAMES         "075"
#define WARNING_KEYFRAMES_TIME_DUPLICATE    LEVEL_WARNING   TOPIC_KEYFRAMES         "076"
#define ERROR_VIDEO_WIDTH_MISSING           LEVEL_ERROR     TOPIC_VIDEO_DATA        "077"
#define ERROR_VIDEO_HEIGHT_MISSING          LEVEL_ERROR     TOPIC_VIDEO_DATA        "078"
#define WARNING_VIDEO_SIZE_ERROR            LEVEL_WARNING   TOPIC_VIDEO_DATA        "079"
#define INFO_VIDEO_CODEC                    LEVEL_INFO      TOPIC_VIDEO_CODECS      "080"
#define INFO_AUDIO_FORMAT                   LEVEL_INFO      TOPIC_AUDIO_CODECS      "081"
#define INFO_TIMESTAMP_USE_EXTENDED         LEVEL_INFO      TOPIC_TIMESTAMPS        "082"
#define INFO_GENERAL_LARGE_FILE             LEVEL_INFO      TOPIC_GENERAL_FORMAT    "083"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* check FLV file validity */
int check_flv_file(const flvmeta_opts * opts);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CHECK_H__ */

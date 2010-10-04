/*
 * Copyright 2010, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "TilesSet.h"

#if USE(ACCELERATED_COMPOSITING)

#ifdef DEBUG

#include <cutils/log.h>
#include <wtf/CurrentTime.h>
#include <wtf/text/CString.h>

#undef XLOG
#define XLOG(...) android_printLog(ANDROID_LOG_DEBUG, "TilesSet", __VA_ARGS__)

#else

#undef XLOG
#define XLOG(...)

#endif // DEBUG

namespace WebCore {

#ifdef DEBUG
static int gTilesSetCount = 0;
int TilesSet::count()
{
    return gTilesSetCount;
}
#endif

TilesSet::TilesSet(int id, float scale, int firstTileX, int firstTileY, int rows, int cols)
    : m_id(id)
    , m_scale(scale)
    , m_firstTileX(firstTileX)
    , m_firstTileY(firstTileY)
    , m_nbRows(rows)
    , m_nbCols(cols)
    , m_painting(false)
{
#ifdef DEBUG
    gTilesSetCount++;
#endif
}

TilesSet::~TilesSet()
{
#ifdef DEBUG
    gTilesSetCount--;
#endif
}

bool TilesSet::operator==(const TilesSet& set)
{
    return (id() == set.id())
           && (firstTileX() == set.firstTileX())
           && (firstTileY() == set.firstTileY())
           && (nbRows() == set.nbRows())
           && (nbCols() == set.nbCols());
}

void TilesSet::reserveTextures()
{
    XLOG("reserveTextures (%d tiles)", mTiles.size());
    for (unsigned int i = 0; i < mTiles.size(); i++)
        mTiles[i]->reserveTexture();
}

void TilesSet::paint()
{
    XLOG("%x, painting %d tiles", this, mTiles.size());
    for (unsigned int i = 0; i < mTiles.size(); i++)
        mTiles[i]->paintBitmap();
    XLOG("%x, end of painting %d tiles", this, mTiles.size());
}

} // namespace WebCore

#endif // USE(ACCELERATED_COMPOSITING)

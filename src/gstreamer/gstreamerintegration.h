/*
 * Copyright 2019 Eike Hein <hein@kde.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KIROGI_GSTREAMER_H
#define KIROGI_GSTREAMER_H

#include <QObject>

#include <gst/gst.h>

class QQuickWindow;

class GStreamerIntegration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged)
    Q_PROPERTY(QString pipeline READ pipeline WRITE setPipeline NOTIFY pipelineChanged)

    public:
        explicit GStreamerIntegration(QObject *parent = nullptr);
        ~GStreamerIntegration();

        bool playing() const;
        void setPlaying(bool playing);

        QString pipeline() const;
        void setPipeline(const QString &pipeline);

        void setWindow(QQuickWindow *window);

    Q_SIGNALS:
        void playingChanged() const;
        void pipelineChanged() const;

    private:
        void updateGstPipeline();

        bool m_playing;

        QString m_pipeline;
        GstElement *m_gstPipeline;

        bool m_fallback;

        QQuickWindow *m_window;
};

#endif

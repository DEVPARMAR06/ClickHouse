#pragma once

#include <Coordination/TinyContext.h>
#include <Common/AsynchronousMetrics.h>

namespace DB
{

class KeeperDispatcher;
void updateKeeperInformation(KeeperDispatcher & keeper_dispatcher, AsynchronousMetricValues & new_values);

class KeeperAsynchronousMetrics : public AsynchronousMetrics
{
public:
    KeeperAsynchronousMetrics(
        const TinyContext & tiny_context_, int update_period_seconds, const ProtocolServerMetricsFunc & protocol_server_metrics_func_);

private:
    const TinyContext & tiny_context;

    void updateImpl(AsynchronousMetricValues & new_values) override;
};


}

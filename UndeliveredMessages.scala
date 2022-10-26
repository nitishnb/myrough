import com.google.cloud.monitoring.v3.MetricServiceClient
import com.google.monitoring.v3.{ListTimeSeriesRequest, ProjectName, TimeInterval}
import com.google.protobuf.util.Timestamps

object UndeliveredMessages {
  def main(args: Array[String]) {
    println("Pub/Sub notifications for Cloud Storage!")

    val metricServiceClient = MetricServiceClient.create
    val projectId = "marksmng"
    val name = ProjectName.of(projectId)

    // Restrict time to last 1 minutes
    val startMillis = System.currentTimeMillis - (100 * 1000)
    val interval = TimeInterval.newBuilder
      .setStartTime(Timestamps.fromMillis(startMillis))
      .setEndTime(Timestamps.fromMillis(System.currentTimeMillis)).build

    val requestBuilder = ListTimeSeriesRequest
      .newBuilder
      .setName(name.toString)
      .setFilter("metric.type=\"pubsub.googleapis.com/subscription/num_undelivered_messages\"")
      .setInterval(interval)

    val request = requestBuilder.build

    val response = metricServiceClient.listTimeSeries(request)

    response.iterateAll().forEach(subscriptionData => {
      print(subscriptionData)
      val subscription = subscriptionData.getResource.getLabelsMap.get("subscription_id")
      val numberOrMessages = subscriptionData.getPointsList.get(0).getValue().getInt64Value()
      println(subscription + " has " + numberOrMessages + " messages ")
    }
    )
  }
}
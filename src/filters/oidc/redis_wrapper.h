#ifndef AUTHSERVICE_TEST_FILTERS_OIDC_REDIS_WRAPPER_H_
#define AUTHSERVICE_TEST_FILTERS_OIDC_REDIS_WRAPPER_H_

#include "redis.h"
#include "absl/strings/string_view.h"
#include "absl/types/optional.h"

namespace authservice {
namespace filters {
namespace oidc {

class RedisWrapper {
 private:
  std::shared_ptr<sw::redis::Redis> redis_;
 public:
  explicit RedisWrapper(std::shared_ptr<sw::redis::Redis> redis);
  virtual absl::optional<std::string> hget(const absl::string_view key, const absl::string_view value);
  virtual bool hset(const absl::string_view key,
                    const absl::string_view field,
                    const absl::string_view val);
  virtual bool hsetnx(const absl::string_view key,
                      const absl::string_view field,
                      const absl::string_view val);
  virtual bool hexists(const absl::string_view key, const absl::string_view field);
  virtual long long del(const absl::string_view key);
  virtual bool expireat(const absl::string_view key, long long timestamp);
  virtual long long hdel(const absl::string_view key, const absl::string_view field);
};

}  // namespace oidc
}  // namespace filters
}  // namespace authservice

#endif //AUTHSERVICE_TEST_FILTERS_OIDC_REDIS_WRAPPER_H_
#ifndef _FF_SPANS_H_
#define _FF_SPANS_H_

#include <vector>
#include "ff.h"
#include "array2d.h"

class SpanFeatures : public FeatureFunction {
 public:
  SpanFeatures(const std::string& param);
 protected:
  virtual void TraversalFeaturesImpl(const SentenceMetadata& smeta,
                                     const Hypergraph::Edge& edge,
                                     const std::vector<const void*>& ant_contexts,
                                     SparseVector<double>* features,
                                     SparseVector<double>* estimated_features,
                                     void* context) const;
  virtual void PrepareForInput(const SentenceMetadata& smeta);
 private:
  const int kS;
  const int kX;
  Array2D<int> span_feats_;
  std::vector<int> end_span_ids_;
};

#endif

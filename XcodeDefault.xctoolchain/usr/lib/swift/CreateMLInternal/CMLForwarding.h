#ifdef CREATEML_INTERNAL

#include <stdio.h>
#include <stdbool.h>

#include <CoreGraphics/CoreGraphics.h>

typedef enum {
    __CMLInt64Type = 0,
    __CMLDoubleType = 1,
    __CMLStringType = 2,
    __CMLSequenceType = 4,
    __CMLDictionaryType = 5,
    __CMLUndefinedType = 7,
    __CMLImageType = 8,
    __CMLMultiArrayType = 9
} __CMLFeatureValueType;


/***** Type declarations *****/
typedef struct __CMLError __CMLError;

typedef struct __CMLFeatureValue __CMLFeatureValue;

typedef struct __CMLSequence __CMLSequence;

typedef struct __CMLFVTypeSequence __CMLFVTypeSequence;

typedef struct __CMLDictionary __CMLDictionary;

typedef struct __CMLMultiArray __CMLMultiArray;

typedef struct __CMLColumn __CMLColumn;

typedef struct __CMLTable __CMLTable;

typedef struct __CMLVariant __CMLVariant;

typedef struct __CMLParameters __CMLParameters;

typedef struct __CMLModel __CMLModel;

typedef struct __CMLAggregator __CMLAggregator;


/***** manual declarations *****/
__CMLFeatureValue *__CMLCreateFeatureValue(void);
__CMLTable *__CMLCreateTable(void);
__CMLSequence *__CMLCreateSequence(void);
__CMLFVTypeSequence *__CMLCreateFVTypeSequence(void);
__CMLDictionary *__CMLCreateDictionary(void);
__CMLParameters *__CMLCreateParameters(void);
__CMLAggregator *__CMLCreateAggregator(void);

void __CMLSave(const __CMLTable *table, const char *path, int type, __CMLError **error);
const char *__CMLTableDescription(const __CMLTable *table, __CMLError **error);

__CMLColumn *__CMLTableApply(const __CMLTable *data,
                             __CMLFeatureValue *(*callback)(__CMLSequence *row, void *context, __CMLError **error),
                             void (*contextRelease)(void *context),
                             void *context,
                             __CMLFeatureValueType type,
                             __CMLError **error);


__CMLColumn *__CMLColumnApply(const __CMLColumn *array,
                              __CMLFeatureValue * (* callback)(__CMLFeatureValue *value,
                                                               void *context,
                                                               __CMLError **error),
                              void (*contextRelease)(void* context),
                              void *context,
                              __CMLFeatureValueType type,
                              bool skipUndefined,
                              __CMLError **error);

__CMLTable *__CMLCreateTableFromPath(const char *path, bool isCSV,const __CMLParameters *para,__CMLError **error);
__CMLTable *__CMLCreateTableFromBinary(const char *path, __CMLError **error);

/***** automatic function declarations *****/
void __CMLDestroyFeatureValue(__CMLFeatureValue* v);
void __CMLDestroySequence(__CMLSequence* v);
void __CMLDestroyFVTypeSequence(__CMLFVTypeSequence* v);
void __CMLDestroyDictionary(__CMLDictionary* v);
void __CMLDestroyMultiArray(__CMLMultiArray* v);
void __CMLDestroyColumn(__CMLColumn* v);
void __CMLDestroyTable(__CMLTable* v);
void __CMLDestroyVariant(__CMLVariant* v);
void __CMLDestroyParameters(__CMLParameters* v);
void __CMLDestroyModel(__CMLModel* v);
void __CMLDestroyAggregator(__CMLAggregator* v);
const char* __CMLErrorMessage(const __CMLError* error);
void __CMLDestroyError(__CMLError* v);
__CMLFeatureValue* __CMLCopyFeatureValue(const __CMLFeatureValue* fv, __CMLError** error);
__CMLFeatureValue* __CMLCreateFeatureValueInt64(int64_t v, __CMLError** error);
__CMLFeatureValue* __CMLCreateFeatureValueDouble(double v, __CMLError** error);
__CMLFeatureValue* __CMLCreateFeatureValueString(const char* str, __CMLError** error);
__CMLFeatureValue* __CMLCreateFeatureValueSequence(const __CMLSequence* seq, __CMLError** error);
__CMLFeatureValue* __CMLCreateFeatureValueDictionary(const __CMLDictionary* d, __CMLError** error);
__CMLFeatureValue* __CMLCreateFeatureValueMultiArray(const __CMLMultiArray* nda, __CMLError** error);
__CMLFeatureValueType __CMLTypeFromFeatureValue(const __CMLFeatureValue* fv);
int __CMLIsStringFeatureValue(const __CMLFeatureValue* fv);
int __CMLIsDoubleFeatureValue(const __CMLFeatureValue* fv);
int __CMLIsIntFeatureValue(const __CMLFeatureValue* fv);
int __CMLIsSequenceFeatureValue(const __CMLFeatureValue* fv);
int __CMLIsUndefinedFeatureValue(const __CMLFeatureValue* fv);
int __CMLIsMultiArrayValue(const __CMLFeatureValue* fv);
int64_t __CMLInt64Value(const __CMLFeatureValue* fv, __CMLError** error);
double __CMLDoubleValue(const __CMLFeatureValue* fv, __CMLError** error);
const char* __CMLStringValue(const __CMLFeatureValue* fv, __CMLError** error);
__CMLSequence* __CMLSequenceValue(const __CMLFeatureValue* fv, __CMLError** error);
__CMLDictionary* __CMLDictionaryValue(const __CMLFeatureValue* fv, __CMLError** error);
__CMLMultiArray* __CMLMultiArrayValue(const __CMLFeatureValue* fv, __CMLError** error);
uint64_t __CMLAppendToSequence(__CMLSequence* seq, const __CMLFeatureValue* fv, __CMLError** error);
__CMLFeatureValue* __CMLGetValue(const __CMLSequence* seq, uint64_t index, __CMLError** error);
uint64_t __CMLSequenceSize(const __CMLSequence* seq);
uint64_t __CMLAppendToFVTypeSequence(__CMLFVTypeSequence *seq, const __CMLFeatureValueType type, __CMLError** error);
uint64_t __CMLDictionarySize(const __CMLDictionary* d);
uint64_t __CMLAddPair(__CMLDictionary* d, const __CMLFeatureValue* first, const __CMLFeatureValue* second, __CMLError** error);
void __CMLGetPair(const __CMLDictionary* d, uint64_t entryIndex, __CMLFeatureValue* keyDest, __CMLFeatureValue* valueDest, __CMLError** error);
__CMLMultiArray* __CMLCreateMultiArray(uint64_t nDim, const uint64_t* shape, const int64_t* strides, const double* data, __CMLError** error);
uint64_t __CMLDimensionCount(const __CMLMultiArray* ndv, __CMLError** error);
const uint64_t* __CMLMultiArrayShape(const __CMLMultiArray* ndv, __CMLError** error);
const int64_t* __CMLMultiArrayStrides(const __CMLMultiArray* ndv, __CMLError** error);
const double* __CMLMultiArrayData(const __CMLMultiArray* ndv, __CMLError** error);
__CMLColumn* __CMLCreateColumnFromRange(uint64_t start, uint64_t end, __CMLError** error);
__CMLColumn* __CMLCreateColumnFromValue(const __CMLFeatureValue* fv, uint64_t n, __CMLError** error);
__CMLColumn* __CMLCreateColumnFromSequence(const __CMLSequence* seq, __CMLError** error);
__CMLColumn* __CMLCreateColumnCopy(const __CMLColumn* col, __CMLError** error);
__CMLFeatureValue* __CMLFeatureValueAtIndex(const __CMLColumn* column, uint64_t index, __CMLError** error);
uint64_t __CMLColumnSize(const __CMLColumn* column);
__CMLFeatureValueType __CMLColumnType(const __CMLColumn* column);
__CMLColumn* __CMLColumnAddColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnSubtractColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnMultiplyColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnDivideColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnLessThanColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnGreaterThanColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnLessThanEqualColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnGreaterThanEqualColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnEqualColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnNotEqualColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnLogicalAndColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnLogicalOrColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnAddValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnSubtractValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnMultiplyValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnDivideValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnLessThanValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnGreaterThanValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnGreaterThanEqualValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnLessThanEqualValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnEqualValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLColumnNotEqualValue(const __CMLColumn* column1, const __CMLFeatureValue* fv2, __CMLError** error);
__CMLColumn* __CMLValueAddColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueSubtractColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueMultiplyColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueDivideColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueLessThanColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueGreaterThanColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueLessThanEqualColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueGreaterThanEqualColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueEqualColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLValueNotEqualColumn(const __CMLFeatureValue* fv1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnMask(const __CMLColumn* column1, const __CMLColumn* mask, __CMLError** error);
__CMLColumn* __CMLAppendingColumn(const __CMLColumn* column1, const __CMLColumn* column2, __CMLError** error);
__CMLColumn* __CMLColumnPrefix(const __CMLColumn* column, uint64_t numberOfRows, __CMLError** error);
__CMLColumn* __CMLColumnSuffix(const __CMLColumn* column, uint64_t numberOfRows, __CMLError** error);
__CMLColumn* __CMLColumnDropMissing(const __CMLColumn* column, __CMLError** error);
__CMLColumn* __CMLColumnFillMissing(const __CMLColumn* column, const __CMLFeatureValue* fv, __CMLError** error);
__CMLColumn* __CMLColumnDropDuplicates(const __CMLColumn* column, __CMLError** error);
__CMLColumn* __CMLColumnSample(const __CMLColumn* column, double fraction, uint64_t seed, __CMLError** error);
__CMLColumn* __CMLColumnToType(const __CMLColumn* column, __CMLFeatureValueType type, bool undefinedReturn, __CMLError** error);
__CMLColumn* __CMLColumnSort(const __CMLColumn* column, bool isAscending, __CMLError** error);
void __CMLColumnMaterialize(__CMLColumn* column1, __CMLError** error);
__CMLFeatureValue* __CMLColumnSum(const __CMLColumn* column, __CMLError** error);
__CMLFeatureValue* __CMLColumnMin(const __CMLColumn* column, __CMLError** error);
__CMLFeatureValue* __CMLColumnMax(const __CMLColumn* column, __CMLError** error);
__CMLFeatureValue* __CMLColumnMean(const __CMLColumn* column, __CMLError** error);
__CMLFeatureValue* __CMLColumnStdev(const __CMLColumn* column, __CMLError** error);
__CMLFeatureValue* __CMLColumnDescription(const __CMLColumn* column, __CMLError** error);
__CMLModel* __CMLColumnPlot(const __CMLColumn* column, __CMLError** error);
__CMLModel* __CML2DPlot(const __CMLColumn* x, const __CMLColumn* y, __CMLError** error);
void __CMLPlotRenderIntoContext(const __CMLModel* plot, CGContextRef context, __CMLError** error);
void __CMLPlotNextIteration(const __CMLModel* plot, __CMLError** error);
bool __CMLPlotFinishedStreaming(const __CMLModel* plot, __CMLError** error);
void __CMLAddColumn(__CMLTable* table, const char* column_name, const __CMLColumn* column, __CMLError** error);
void __CMLRemoveColumn(__CMLTable* table, const char* column_name, __CMLError** error);
void __CMLRenameColumn(__CMLTable* table, const char* previousName, const char* newName, __CMLError** error);
__CMLColumn* __CMLGetColumn(__CMLTable* table, const char* column_name, __CMLError** error);
uint64_t __CMLTableRows(const __CMLTable* table, __CMLError** error);
uint64_t __CMLTableColumns(const __CMLTable* table, __CMLError** error);
__CMLFeatureValueType __CMLTableColumnType(const __CMLTable* table, const char* column_name, __CMLError** error);
__CMLSequence* __CMLTableColumnNames(const __CMLTable* table, __CMLError** error);
__CMLTable* __CMLTableSort(const __CMLTable* table,  const char* columnName, bool isAscending, __CMLError** error);
__CMLTable* __CMLTablePrefix(const __CMLTable* table, size_t numberOfRows, __CMLError** error);
__CMLTable* __CMLTableSuffix(const __CMLTable* table, size_t numberOfRows, __CMLError** error);
__CMLTable* __CMLTableDropMissing(const __CMLTable* table, const __CMLSequence* columnNames, const char *how, __CMLError** error);
__CMLTable* __CMLTableFillMissing(const __CMLTable* table, const char* columnName, const __CMLFeatureValue* fv, __CMLError** error);
__CMLTable* __CMLTableDropDuplicates(const __CMLTable* table, __CMLError** error);
__CMLTable* __CMLTableSample(const __CMLTable* table, double fraction, uint64_t seed, __CMLError** error);
__CMLTable* __CMLTableStack(const __CMLTable* table, const char* columnName, const char* newColumnName, __CMLError** error);
__CMLTable* __CMLTableUnStack(const __CMLTable* table, const char* columnName, const char* newColumnName, __CMLError** error);
__CMLTable* __CMLTablePack(const __CMLTable* table,
                           const __CMLSequence* columnNames,
                           const char *newColumnName,
                           __CMLFeatureValueType type,
                           __CMLFeatureValue* value,
                           __CMLError** error);
__CMLTable* __CMLTableUnPack(const __CMLTable* table,
                             const char* columnName,
                             const char* columnPrefix,
                             const __CMLFVTypeSequence* types,
                             __CMLFeatureValue* value,
                             const __CMLSequence* limit,
                             __CMLError** error);
void __CMLSplit(const __CMLTable* table, double fraction, size_t seed, __CMLTable** left, __CMLTable** right, __CMLError** error);
__CMLSequence* __CMLGetRow(const __CMLTable* table, const uint64_t row, __CMLError** error);
__CMLTable* __CMLFiltering(const __CMLTable* table,
                           const __CMLColumn* values,
                           const char* columnName,
                           bool exclude,
                           __CMLError** error);
__CMLTable* __CMLJoining(__CMLTable* left,
                         __CMLTable* right,
                         const char* column,
                         const char* how,
                         __CMLError** error);
__CMLTable* __CMLJoiningMultiple(__CMLTable* left,
                                 __CMLTable* right,
                                 __CMLSequence* columnNames,
                                 const char* how,
                                 __CMLError** error);
__CMLTable* __CMLGrouping(__CMLTable* table, __CMLSequence* columnNames, __CMLAggregator* aggregator, __CMLError** error);
void __CMLAddAggregatorOperation(__CMLAggregator* aggregator, const char* op, const char* toColumnName,
                                 const char* fromColumnName, __CMLError** error);
void __CMLAddAggregatorArg(__CMLAggregator* aggregator, bool isMax, const char* toColumnName, const char* aggColumnName,
                           const char* outputColumnName, __CMLError** error);
void __CMLAddAggregatorQuantile(__CMLAggregator* aggregator, const char* toColumnName, const char* fromColumnName,
                                const double quantile, __CMLError** error);
void __CMLAddAggregatorQuantiles(__CMLAggregator* aggregator, const char* toColumnName, const char* fromColumnName,
                                 __CMLSequence *quantiles, __CMLError** error);
void __CMLAddAggregatorConcat(__CMLAggregator* aggregator, const char* toColumnName, const char* keyColumnName,
                              const char* valColumnName, __CMLError** error);
__CMLTable* __CMLAppending(__CMLTable* top, __CMLTable* bottom, __CMLError** error);
__CMLFeatureValue* __CMLFeatureValueFromVariant(const __CMLVariant* var, __CMLError** error);
int64_t __CMLInt64FromVariant(const __CMLVariant* var, __CMLError** error);
__CMLColumn* __CMLColumnFromVariant(const __CMLVariant* var, __CMLError** error);
__CMLModel* __CMLModelFromVariant(const __CMLVariant* var, __CMLError** error);
__CMLTable* __CMLTableFromVariant(const __CMLVariant* var, __CMLError** error);
__CMLParameters* __CMLParametersFromVariant(const __CMLVariant* var, __CMLError** error);
bool __CMLParametersContains(const __CMLParameters* params, const char* name, __CMLError** error);
__CMLVariant* __CMLVariantForParameterKey(const __CMLParameters* params, const char* name, __CMLError** error);
void __CMLAddFeatureValueParameter(__CMLParameters* params, const char* name, const __CMLFeatureValue* fv, __CMLError** error);
void __CMLAddColumnParameter(__CMLParameters* params, const char* name, const __CMLColumn* column, __CMLError** error);
void __CMLAddTableParameter(__CMLParameters* params, const char* name, const __CMLTable* table, __CMLError** error);
void __CMLAddParameterParameter(__CMLParameters* params, const char* name, const __CMLParameters* p, __CMLError** error);
bool __CMLIsFeatureValue(const __CMLVariant* variant);
bool __CMLIsInt64(const __CMLVariant* variant);
bool __CMLIsColumn(const __CMLVariant* variant);
bool __CMLIsModel(const __CMLVariant* variant);
bool __CMLIsFrame(const __CMLVariant* variant);
bool __CMLIsParameters(const __CMLVariant* variant);
__CMLFeatureValue* __CMLFeatureValueForParameterKey(const __CMLParameters* params, const char* name, __CMLError** error);
__CMLColumn* __CMLColumnForParameterKey(const __CMLParameters* params, const char* name, __CMLError** error);
__CMLTable* __CMLTableForParameterKey(const __CMLParameters* params, const char* name, __CMLError** error);
__CMLModel* __CMLCreateModel(const char* model_name, __CMLError** error);
__CMLModel* __CMLLoadModel(const char* url, __CMLError** error);
const char* __CMLModelName(const __CMLModel* model, __CMLError** error);
__CMLVariant* __CMLModelFunction(const __CMLModel* model, const char* method, const __CMLParameters* arguments, __CMLError** error);
__CMLVariant* __CMLFunction(const char* function_name, const __CMLParameters* arguments, __CMLError** error);
__CMLColumn* __CMLReduceCol(const __CMLColumn* sa, const char* op, __CMLError** error);
__CMLTable* __CMLTableSlice(const __CMLTable* sf, const int64_t start, const int64_t end, const int64_t stride, __CMLError** error);

#endif

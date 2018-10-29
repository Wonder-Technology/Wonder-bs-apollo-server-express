/* This one should be moved to its own package once we add the next apollo-server variant */
type logAction = string;

type logStep = string;

type logMessage = {
  .
  "action": logAction,
  "step": logStep,
  "key": Js.Nullable.t(string),
  "data": Js.Nullable.t(Js.Types.obj_val),
};

type graphqlOptions('rootValue, 'context, 'response) = {
  .
  "schema": WonderBsGraphql.GraphQL.Type.schema,
  "formatError":
    Js.Nullable.t(Js.Exn.t => WonderBsGraphql.GraphQL.Error.error),
  "rootValue": Js.Nullable.t('rootValue),
  "context": Js.Nullable.t('context),
  "logFunction": Js.Nullable.t(logMessage => unit),
  "formatParams": Js.Nullable.t(Js.Types.obj_val => Js.Types.obj_val),
  "validationRules":
    Js.Nullable.t(WonderBsGraphql.GraphQL.Validation.validationContext),
  "formatResponse":
    Js.Nullable.t(
      WonderBsGraphql.GraphQL.Execution.executionResult(
        Js.Types.obj_val => 'response,
      ),
    ),
  "fieldResolver":
    Js.Nullable.t(
      WonderBsGraphql.GraphQL.Type.fieldResolver(
        Js.Types.obj_val,
        Js.Types.obj_val,
      ),
    ),
  "debug": Js.Nullable.t(bool),
};

type graphiqlData('variables) = {
  .
  "endpointURL": string,
  "query": Js.Nullable.t(string),
  "variables": Js.Nullable.t('variables),
  "operationName": Js.Nullable.t(string),
  "result": Js.Nullable.t(string),
};
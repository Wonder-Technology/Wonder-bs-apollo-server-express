/**
 * Represents a function taking express request and response to output a promise for some graphqlOptions
 */
type expressGraphQLOptionsFunction('rootValue, 'context, 'response) =
  (Express.Request.t, Express.Response.t) =>
  Js.Promise.t(
    ApolloServerCore.graphqlOptions('rootValue, 'context, 'response),
  );

/**
 * Represents a function taking express request to output a promise for some GraphiQL data
 */
type expressGraphiQLOptionsFunction('variables) =
  Express.Request.t =>
  Js.Promise.t(ApolloServerCore.graphiqlData('variables));

/**
 * Calls the graphqlExpress middleware creation with static options
 */
[@bs.module "apollo-server-express"]
external graphqlExpress :
  ApolloServerCore.graphqlOptions('rootValue, 'context, 'response) =>
  Express.Middleware.t =
  "graphqlExpress";

/**
 * Calls the graphqlExpress middleware creation with function options
 */
[@bs.module "apollo-server-express"]
external graphqlExpressAsync :
  expressGraphQLOptionsFunction('rootValue, 'context, 'response) =>
  Express.Middleware.t =
  "graphqlExpress";

/**
 * Calls the graphiqlExpress middleware creation with static options
 */
[@bs.module "apollo-server-express"]
external graphiqlExpress :
  ApolloServerCore.graphiqlData('variables) => Express.Middleware.t =
  "graphiqlExpress";

/**
 * Calls the graphiqlExpress middleware creation with function options
 */
[@bs.module "apollo-server-express"]
external graphiqlExpressAsync :
  expressGraphiQLOptionsFunction('variables) => Express.Middleware.t =
  "graphiqlExpress";

/**
 * Usability wrapper around the static graphqlExpress function
 */
let createGraphQLExpressMiddleware =
    (
      ~formatError=?,
      ~rootValue=?,
      ~context=?,
      ~logFunction=?,
      ~formatParams=?,
      ~validationRules=?,
      ~formatResponse=?,
      ~fieldResolver=?,
      ~debug=?,
      schema,
      (),
    ) =>
  graphqlExpress({
    "schema": schema,
    "formatError": Js.Nullable.fromOption(formatError),
    "rootValue": Js.Nullable.fromOption(rootValue),
    "context": Js.Nullable.fromOption(context),
    "logFunction": Js.Nullable.fromOption(logFunction),
    "formatParams": Js.Nullable.fromOption(formatParams),
    "validationRules": Js.Nullable.fromOption(validationRules),
    "formatResponse": Js.Nullable.fromOption(formatResponse),
    "fieldResolver": Js.Nullable.fromOption(fieldResolver),
    "debug": Js.Nullable.fromOption(debug),
  });

/**
 * Usability wrapper around the static graphiqlExpress function
 */
let createGraphiQLExpressMiddleware =
    (~query=?, ~variables=?, ~operationName=?, ~result=?, endpointURL, ()) =>
  graphiqlExpress({
    "endpointURL": endpointURL,
    "query": Js.Nullable.fromOption(query),
    "variables": Js.Nullable.fromOption(variables),
    "operationName": Js.Nullable.fromOption(operationName),
    "result": Js.Nullable.fromOption(result),
  });